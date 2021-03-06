#include <gtest/gtest.h>
#include <LoRDeck.h>
#include <LoRCard.h>

#include <vector>
#include <string>
#include <fstream>

using namespace std;

TEST(TestReadyDecks, ReadFromFile ) {
    vector<LoRDeck> decks;
    vector<string> codeDecks;
    string file_path = __FILE__;
    string dir_path = file_path.substr(0, file_path.rfind('/'));
    ifstream test_file(dir_path + "/" + "DeckCodesTestData.txt");
    string line;

    while (std::getline(test_file, line)) {
        codeDecks.emplace_back(line);
        LoRDeck deck(1);
        while (getline(test_file, line)) {
            if (line.empty()) break;
            int amount;
            char separator;
            string cardCode;
            stringstream(line) >> amount >> separator >> cardCode >> separator;
            deck.add_cards(cardCode, amount);
        }
        decks.emplace_back(deck);
    }

    for (int i = 0; i < decks.size(); i++) {
        string encoded = decks[i].encode();
        EXPECT_EQ(encoded, codeDecks[i]);

        auto decoded_deck = LoRDeck::decode(codeDecks[i]);
        auto deck_cards = decks[i].getDeckCards();
        for (int j = 0; j < decoded_deck.size(); j++) {
            EXPECT_EQ(decoded_deck[j].getFullCode(), deck_cards[j].getFullCode());
        }
    }
}
