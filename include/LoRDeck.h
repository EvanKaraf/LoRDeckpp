#ifndef LORDECK___LORDECK_H
#define LORDECK___LORDECK_H

#include <vector>
#include "LoRCard.h"

typedef std::pair<LoRCard, int> LoRCardAndCount;
typedef std::pair<std::string, LoRFaction> SetFaction;

class LoRDeck {
    std::vector<LoRCardAndCount> deck;

    static std::vector<LoRCard> decode_group(std::vector<uint8_t>* card_stream, int group_amount);

    std::string encode_group(const std::vector<LoRCardAndCount>& cards);

    // The first return argument is a vector of set / faction combinations
    // and the second is all the cards grouped by faction
    std::pair< std::vector<SetFaction>, std::vector<std::vector<LoRCard>> >
    getProcessedGroups(const std::vector<LoRCardAndCount>& cards) const;
public:
    bool add_cards(const LoRCard &card, int amount);
    std::string encode();
    static std::vector<LoRCard> decode(const std::string& encoded_deck);
};


#endif //LORDECK___LORDECK_H
