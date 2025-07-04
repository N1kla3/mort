#include "core.h"
#include "gtest/gtest.h"

TEST(mortcore, zerofloat)
{
    // float
    float totest = 0.00001f;
    EXPECT_TRUE(mort::isNearlyZero(totest, 0.0001f));
    EXPECT_FALSE(mort::isNearlyZero(totest, 0.0000001f));
    EXPECT_TRUE(mort::isNearlyZero(0.f));
}

TEST(mortcore, zerodouble)
{
    // float
    double totest = 0.00001;
    EXPECT_TRUE(mort::isNearlyZero(totest, 0.0001));
    EXPECT_FALSE(mort::isNearlyZero(totest, 0.0000001));
    EXPECT_TRUE(mort::isNearlyZero(0.0));
}

TEST(mortcore, equalityfloat)
{
    float totest = 0.5f;
    for (int i = 0; i < 11; i++)
    {
        totest += 0.1f;
        totest *= 2.2222222f;
        totest /= 2.2222222f;
    }
    float res = 1.6000f;
    EXPECT_TRUE(mort::isNearlyEqual(totest, res));
    EXPECT_TRUE(mort::isEqualWithPrecision(totest, res, 2));
    EXPECT_FALSE(totest == res);
}

TEST(mortcore, equalitydouble)
{
    double totest = 0.5;
    for (int i = 0; i < 11; i++)
    {
        totest += 0.1;
        totest *= 2.2222222;
        totest /= 2.2222222;
    }
    double res = 1.6000;
    EXPECT_TRUE(mort::isNearlyEqual(totest, res));
    EXPECT_TRUE(mort::isEqualWithPrecision(totest, res, 2));
    EXPECT_FALSE(totest == res);
}

TEST(mortcore, falsetest)
{
    EXPECT_FALSE(mort::isNearlyEqual(24.45666f, 88.434f));
    EXPECT_FALSE(mort::isNearlyEqual(24.45666, 88.434));

    // ULP
    EXPECT_FALSE(mort::isEqualWithPrecision(24.45666f, 88.434f));
    EXPECT_FALSE(mort::isEqualWithPrecision(24.45666, 88.434));

    EXPECT_FALSE(mort::isEqualWithPrecision(24.45666f, 88.434f, 2));
    EXPECT_FALSE(mort::isEqualWithPrecision(24.45666, 88.434, 2));

    EXPECT_FALSE(mort::isEqualWithPrecision(24.45666f, 88.434f, 3));
    EXPECT_FALSE(mort::isEqualWithPrecision(24.45666, 88.434, 3));
}
