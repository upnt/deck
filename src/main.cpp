#include <iostream>
#include "deck.h"
#include "card.h"
#include "deck_db.h"
#include "card_db.h"
#include "database.h"

using std::cin;
using std::cout;
using std::endl;

template<typename T>
int input_index(Database<T>& db) {
    int index = 0;
    string text;

    db.print();
    cout << endl;
    cout << "ender \"end\" if you want to end" << endl;

    do {
        cout << "index: ";
        cin >> text;
        if(text == "end") break;
        try {
            index = std::stoi(text);
        } catch(std::exception e) {
            index = db.size();
        }
    } while(index >= db.size());

    return index;
}

void print_top(Deck deck) {
    Card top_card;
    for(int i = 0; i < 5 ; i++) {
        if(deck.empty())
            cout << "Deck is empty" << endl;
            return;
        top_card = deck.draw();
        cout << top_card.get_name() << endl;
    }
}

int main() {
    // DeckDB db("decks");
    CardDB db("card.txt");

    int index = input_index(db);

    // auto deck = db.load(index);
    Deck deck;
    deck.add(db.load(index));
    deck.shuffle();

    print_top(deck);

    return 0;
}
