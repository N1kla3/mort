#include <cstdint>
#include "gtest/gtest.h"
#include "vec3.hpp"

TEST(vector3, basic)
{
    using vec = mort::Vector3<float>;
    using veci = mort::Vector3<int32_t>;

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
