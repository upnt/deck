#include "deck.h"
#include "card.h"
#include "gtest/gtest.h"
#include <string>

using std::string;

TEST(DeckTest, Storaged) {
    Deck deck;
    deck.add(Card("name"));
    deck.add(Card("test name"));
    EXPECT_EQ("test name", deck.draw().get_name());
    EXPECT_EQ("name", deck.draw().get_name());
}

TEST(DeckTest, Empty) {
    Deck deck;
    EXPECT_EQ(true, deck.empty());
    deck.add(Card("name"));
    deck.add(Card("test name"));
    EXPECT_EQ(false, deck.empty());
    deck.draw();
    EXPECT_EQ(false, deck.empty());
    deck.draw();
    EXPECT_EQ(true, deck.empty());
}
