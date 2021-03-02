#include <iostream>
#include "deck.h"
#include "deck_db.h"
#include "card_db.h"
#include "database.h"

using std::cout;
using std::endl;


template<typename T>
int input_index(Database<T>& db) {
    db.print();

    return 0;
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
