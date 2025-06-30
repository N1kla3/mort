#include <cstdint>
#include "core.h"
#include "gtest/gtest.h"

TEST(mortcore, zero)
{
    EXPECT_TRUE(mort::isNearlyZero(0.00001f));
}
