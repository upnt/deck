#ifndef DECK_H
#define DECK_H
#include <vector>
#include <random>
#include <algorithm>

#include "card.h"

template <typename T>
using vector = std::vector<T>;
using std::random_device;
using std::mt19937;
using std::string;

class Deck {
    private:
    vector<Card> deck;
    public:
    void add(const Card& card) {
        deck.push_back(card);
    }

    void add(Card&& card) {
        deck.push_back(card);
    }

    void shuffle() {
        if(deck.size() == 1)
            return;
        random_device seed;
        mt19937 engine(seed());
        std::shuffle(deck.begin(), deck.end(), engine);
    }

    Card draw() {
        auto card = deck.back();
        deck.pop_back();
        return card;
    }

    bool empty() {
        return deck.empty();
    }
};
#endif
