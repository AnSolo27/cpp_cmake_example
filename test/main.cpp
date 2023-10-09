#include "gtest/gtest.h"

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    EXPECT_EQ (0,  0);
    EXPECT_EQ (20, 20);
    EXPECT_EQ (100, 100);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}