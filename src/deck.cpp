#include <random>
#include <algorithm>

#include "deck.h"
#include "card.h"

using std::random_device;
using std::mt19937;
using std::string;

void Deck::add(const Card& card) {
    deck.push_back(card);
}

void Deck::add(Card&& card) {
    deck.push_back(card);
}

void Deck::shuffle() {
    if(deck.size() == 1)
        return;
    random_device seed;
    mt19937 engine(seed());
    std::shuffle(deck.begin(), deck.end(), engine);
}

Card Deck::draw() {
    auto card = deck.back();
    deck.pop_back();
    return card;
}

bool Deck::empty() {
    return deck.empty();
}
