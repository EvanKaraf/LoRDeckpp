#include <iostream>
#include "LoRCard.h"
#include "LoRDeck.h"

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

    return 0;
}
//3:01SI015
//3:01SI044
//3:01SI048
//3:01SI054
//3:01FR003
//3:01FR012
//3:01FR020
//3:01FR024
//3:01FR033
//3:01FR036
//3:01FR039
//3:01FR052
//2:01SI005
//2:01FR004