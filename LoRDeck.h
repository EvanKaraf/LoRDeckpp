#ifndef LORDECK___LORDECK_H
#define LORDECK___LORDECK_H

#include <vector>
#include "LoRCard.h"

typedef std::pair<LoRCard, int> LoRCardAndCount;

class LoRDeck {
    std::vector<LoRCardAndCount> deck;
    std::string encode_group(const std::vector<LoRCardAndCount>& cards);
public:
    bool add_cards(const LoRCard &card, int amount);
    std::string encode();
};


#endif //LORDECK___LORDECK_H
