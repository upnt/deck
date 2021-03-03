#ifndef DECK_H
#define DECK_H
#include <vector>

#include "card.h"

template <typename T>
using vector = std::vector<T>;

class Deck {
    private:
    vector<Card> deck;
    public:
    void add(const Card& card);
    void add(Card&& card);
    void shuffle();
    Card draw();
    bool empty();
};
#endif
