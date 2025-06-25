#include "gtest/gtest.h"
#include "vec.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
    mort::Vector<float, 2> a;
    a[0] = 1;
    a.getByIndex<1>() = 1;
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}
