#include <algorithm>
#include <set>
#include <iostream>
#include "../include/LoRDeck.h"
#include "base32_rfc4648.hpp"

using namespace std;
bool LoRDeck::add_cards(const LoRCard &card, int amount) {
    if (amount > 3)
        return false;
    this->deck.emplace_back(make_pair(card, amount));
    return true;
}

std::string LoRDeck::encode() {
    vector<LoRCardAndCount> single_cards;
    vector<LoRCardAndCount> double_cards;
    vector<LoRCardAndCount> triple_cards;
    auto filter_single = [](const LoRCardAndCount& p){return p.second == 1;};
    auto filter_double = [](const LoRCardAndCount& p){return p.second == 2;};
    auto filter_triple = [](const LoRCardAndCount& p){return p.second == 3;};
    std::copy_if(deck.begin(), deck.end(), std::back_inserter(single_cards), filter_single);
    std::copy_if(deck.begin(), deck.end(), std::back_inserter(double_cards), filter_double);
    std::copy_if(deck.begin(), deck.end(), std::back_inserter(triple_cards), filter_triple);


    string encoded_deck;
    writeVarint(&encoded_deck, 18);
    encoded_deck += encode_group(triple_cards) + encode_group(double_cards) + encode_group(single_cards);
    encoded_deck = cppcodec::base32_rfc4648 ::encode(encoded_deck);
    encoded_deck.erase(remove(encoded_deck.begin(), encoded_deck.end(), '='), encoded_deck.end());
    return encoded_deck;
}

std::string LoRDeck::encode_group(const vector<LoRCardAndCount>& cards) {
    typedef pair<string, LoRFaction> SetFaction;

    string             group_encoded;
    set<string>        sets;
    set<LoRFaction>    factions;
    vector<SetFaction> set_faction_combs;

    // Get all possible set faction combos
    for (const auto& c : cards) {
        sets.insert(c.first.getSet());
        factions.insert(c.first.getFaction());
    }
    for (const auto& set : sets) {
        for (const auto& faction : factions) {
            set_faction_combs.emplace_back(make_pair(set, faction));
        }
    }

    // Split cards by faction / set
    vector<vector<LoRCard>> cards_by_faction(factionToInt(LoRFaction::FactionAmount), vector<LoRCard>());
    for (const auto& faction : factions) {
        for (const auto& card : cards) {
            if (card.first.getFaction() == faction) {
                cards_by_faction[factionToInt(faction)].emplace_back(card.first);
            }
        }
    }

    // Sort cards in each faction alphanumerically
    for (auto& v : cards_by_faction) {
        sort(v.begin(), v.end(), [](const LoRCard& lhs, const LoRCard& rhs) {
            return lhs.getFullCode() < rhs.getFullCode();});
    }

    // Sort all combinations based on size
    sort(set_faction_combs.begin(), set_faction_combs.end(), [&cards_by_faction](const SetFaction& lhs, const SetFaction& rhs) {
       return cards_by_faction[factionToInt(lhs.second)].size() < cards_by_faction[factionToInt(rhs.second)].size();
    });

    writeVarint(&group_encoded, set_faction_combs.size());
    for (const auto& p : set_faction_combs) {

        auto set            = stoi(p.first);
        auto faction_idx    = factionToInt(p.second);
        auto& faction_cards = cards_by_faction[faction_idx];

        writeVarint(&group_encoded, faction_cards.size());
        writeVarint(&group_encoded, set);
        writeVarint(&group_encoded, faction_idx);
        for (const auto& card : faction_cards)
            writeVarint(&group_encoded, stoi(card.getCardCode()));
    }

    return group_encoded;
}