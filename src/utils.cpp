#include <utils.h>

using namespace std;
#include <iostream>
#include <algorithm>

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

std::string factionToString(const LoRFaction& faction){
    for (const auto& p : mappings) {
        if (p.second == faction)
            return p.first;
    }
    return "";
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

int getNextVarInt(vector<uint8_t>* stream ) {
    if (stream->empty()) return -1;
    int n_read = 0;
    int result = 0;
    int shift  = 0;
    while (true) {
        uint8_t c = (*stream)[n_read++];
        result |= (c & 0x07f) << shift;
        shift += 7;
        if (!(c & 0x80))
            break;
    }
    stream->erase(stream->begin(), stream->begin() + n_read);
    return result;
}