#include <iostream>
#include "../include/LoRCard.h"
#include "../include/LoRDeck.h"

using namespace std;
int main() {
    LoRDeck deck;
    deck.add_cards({"01SI015"}, 3);
    deck.add_cards({"01SI044"}, 3);
    deck.add_cards({"01SI048"}, 3);
    deck.add_cards({"01SI054"}, 3);
    deck.add_cards({"01FR003"}, 3);
    deck.add_cards({"01FR012"}, 3);
    deck.add_cards({"01FR020"}, 3);
    deck.add_cards({"01FR024"}, 3);
    deck.add_cards({"01FR033"}, 3);
    deck.add_cards({"01FR036"}, 3);
    deck.add_cards({"01FR039"}, 3);
    deck.add_cards({"01FR052"}, 3);
    deck.add_cards({"01SI005"}, 2);
    deck.add_cards({"01FR004"}, 2);
    cout << deck.encode() << endl;

    auto cards = LoRDeck::decode(deck.encode());

    for (const auto& card : cards) {
        cout << card.getFullCode() << endl;
    }

    return 0;
}