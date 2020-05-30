#ifndef LORDECK_UTILS_H
#define LORDECK_UTILS_H


#include <string>
#include <vector>

enum class LoRFaction {
    Demacia = 0,
    Freljord = 1,
    Ionia = 2,
    Noxus = 3,
    Piltover_Zaun = 4,
    Shadow_Isles = 5,
    Bilgewater = 6,
    FactionAmount = 7
};


const std::vector<std::pair<std::string, LoRFaction>> mappings{{"DE", LoRFaction::Demacia},
                                                               {"FR", LoRFaction::Freljord},
                                                               {"IO", LoRFaction::Ionia},
                                                               {"NO", LoRFaction::Noxus},
                                                               {"PZ", LoRFaction::Piltover_Zaun},
                                                               {"SI", LoRFaction::Shadow_Isles},
                                                               {"BW", LoRFaction::Bilgewater}};


LoRFaction toFaction(const std::string& s);

int factionToInt(LoRFaction faction);

int writeVarint(std::string* buffer, uint64_t value);

#endif //LORDECK_UTILS_H
