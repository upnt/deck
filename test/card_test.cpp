#include "card.h"
#include "gtest/gtest.h"
#include <string>

using std::string;

TEST(FactorialTest, Storaged) {
    Card card("name");
    EXPECT_EQ("name", card.get_name());
}

TEST(FactorialTest, NoName) {
    Card card1;
    Card card2("");
    EXPECT_EQ("", card1.get_name());
    EXPECT_EQ("", card2.get_name());
}
