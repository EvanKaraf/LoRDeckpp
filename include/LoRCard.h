#ifndef LORDECK___LORCARD_H
#define LORDECK___LORCARD_H


#include <string>
#include "utils.h"

class LoRCard {
private:
    std::string cardCode;
    LoRFaction faction;
    std::string set;
    std::string fullCode;
public:
    LoRCard(const std::string& cardCode);

    LoRCard(const std::string& set, const std::string& faction, const std::string& cardCode);

    const std::string& getCardCode() const;

    LoRFaction getFaction() const;

    const std::string& getSet() const;

    const std::string& getFullCode() const;
};


#endif //LORDECK___LORCARD_H
