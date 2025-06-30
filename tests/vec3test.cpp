#include <cstdint>
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
    vec tonorm(5.f, 9.f, 11.f);
    tonorm.normalize();
    EXPECT_EQ(tonorm.len(), 1.f);
    EXPECT_EQ(tonorm.lenSqr(), 1.f);
}
