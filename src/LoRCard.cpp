#include <LoRCard.h>

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

LoRCard::LoRCard(const std::string& set, const std::string& faction, const std::string& cardCode) {
    this->set = set;
    if (this->set.size() < 2){
        this->set.insert(this->set.begin(), 2 - this->set.size(), '0');
    }
    this->faction = toFaction(faction);
    this->cardCode = cardCode;
    if (this->cardCode.size() < 3) {
        this->cardCode.insert(this->cardCode.begin(), 3 - this->cardCode.size(), '0');
    }
    this->fullCode = this->set + faction + this->cardCode;
}
