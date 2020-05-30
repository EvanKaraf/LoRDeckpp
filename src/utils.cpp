#include "../include/utils.h"

using namespace std;
#include <iostream>
LoRFaction toFaction(const string& s) {
    for (const auto& p : mappings) {
        if (p.first == s)
            return p.second;
    }
    return LoRFaction::FactionAmount;
}

int factionToInt(LoRFaction faction) {
    return static_cast<underlying_type<LoRFaction>::type>(faction);
}

int writeVarint(string* buffer, uint64_t value) {
    int encoded = 0;

    do {
        uint8_t next_byte = value & 0x7F;
        value >>= 7;

        if (value)
            next_byte |= 0x80;

        (*buffer) += next_byte;
        encoded++;

    } while (value);


    return encoded;
}