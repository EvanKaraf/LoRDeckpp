#include "../include/LoRCard.h"

LoRCard::LoRCard(const std::string& cardCode) : cardCode(cardCode) {
    this->set = cardCode.substr(0, 2);
    this->faction = toFaction(cardCode.substr(2, 2));
    this->cardCode = cardCode.substr(4);
    this->fullCode = cardCode;
}

const std::string& LoRCard::getCardCode() const {
    return cardCode;
}

LoRFaction LoRCard::getFaction() const {
    return faction;
}

const std::string& LoRCard::getSet() const {
    return set;
}

const std::string& LoRCard::getFullCode() const {
    return fullCode;
}
