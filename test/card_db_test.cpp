#include "card_db.h"
#include "gtest/gtest.h"

TEST(CardDBTest, Size) {
    CardDB db("card_db.txt");
    EXPECT_EQ(0, db.size());
}
