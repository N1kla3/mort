#include <cstdint>
#include "core.h"
#include "gtest/gtest.h"
#include "vec3.hpp"

using vec = mort::Vector3<float>;
using veci = mort::Vector3<int32_t>;
using vecd = mort::Vector3<double>;

TEST(vector3, basic)
{
    vec first;
    first.x = 4.f;
    vec second;
    second = vec(5.f, 5.f, 6.f);

    auto res = first - second;

    EXPECT_EQ(res.x, -1.f);

    EXPECT_TRUE(sizeof(mort::Vector3<float>) == 3 * sizeof(float));


    mort::Vector3<int32_t> b;
    mort::Vector3<int32_t> c;
    auto d = b + c;
}

TEST(vector3, normalization)
{
    vec tonorm(5.5f, 9.3f, 11.7f);
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.f));

    // big number
    tonorm = vec(13424.34f, 54034.4545f, 910213.589f);
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.f));

    // small number
    tonorm = vec(0.00134244f, 0.0005445f, 0.00009109f);
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.f));
}
