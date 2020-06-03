# LoRDeck++

This project is a C++ implementation of [Riot's Deck API](google.com) for Legends of Runeterra.

## Installation && Tests

```bash
$ git clone https://github.com/EvanKaraf/LoRDeckpp.git
$ cd  LoRDeckpp
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./DeckTest
```

## Example usage

```c++
#include <iostream>
#include <LoRCard.h>
#include <LoRDeck.h>

using namespace std;
int main() {

    LoRDeck deck;
    LoRCard card("01PZ004");
    deck.add_cards(card, 3);
    deck.add_cards({"01PZ009"}, 3);
    deck.add_cards({"01PZ036"}, 3);
    deck.add_cards({"01PZ052"}, 3);
    deck.add_cards({"01IO006"}, 3);
    deck.add_cards({"01IO009"}, 3);
    deck.add_cards({"01IO012"}, 3);
    deck.add_cards({"01IO017"}, 3);
    deck.add_cards({"01IO021"}, 3);
    deck.add_cards({"01IO042"}, 3);
    deck.add_cards({"01IO044"}, 3);
    deck.add_cards({"01IO048"}, 3);
    deck.add_cards({"01IO011"}, 2);
    deck.add_cards({"01PZ002"}, 2);
    string encoded =  deck.encode();

    auto cards = LoRDeck::decode(encoded);

    for (const auto& card : cards) {
        cout << card.getFullCode() << endl;
    }

    return 0;
}
```

### Dependencies

* [Base32 de(en)coder](https://github.com/tplgy/cppcodec) by @tplgy
* [Google Tests](https://github.com/google/googletest)
