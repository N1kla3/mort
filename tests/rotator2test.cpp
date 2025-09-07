#include <cstdint>
#include "core.h"
#include "gtest/gtest.h"
#include "rotator2.hpp"

using rot = mort::Rotator2;
using vec = mort::Vector2<float>;

TEST(rotator2, base)
{
    rot a(45.f);
    rot b(90.f);
    EXPECT_TRUE((a + b) == rot(135.f));
    EXPECT_TRUE((a + b) == (b + a));
    EXPECT_TRUE((a - b) == rot(-45.f));
    EXPECT_TRUE((a * 3) == rot(135.f));
    EXPECT_TRUE((3 * a) == rot(135.f));
    EXPECT_TRUE((a / 3) == rot(15.f));

    EXPECT_TRUE((a * 3.f) == rot(135.f));
    EXPECT_TRUE((3.f * a) == rot(135.f));
    EXPECT_TRUE((a / 3.f) == rot(15.f));

    EXPECT_TRUE((a * 3.0) == rot(135.f));
    EXPECT_TRUE((3.0 * a) == rot(135.f));
    EXPECT_TRUE((a / 3.0) == rot(15.f));
}

TEST(rotator2, conversion)
{
    vec p45(1.f, 1.f);
    vec p135(-1.f, 1.f);
    vec p225(-1.f, -1.f);
    vec p315(1.f, -1.f);

    EXPECT_TRUE(rot(p45).getAngle360() == 45.f);
    EXPECT_TRUE(rot(p135).getAngle360() == 135.f);
    EXPECT_TRUE(rot(p225).getAngle360() == 225.f);
    EXPECT_TRUE(rot(p315).getAngle360() == 315.f);

    EXPECT_TRUE(rot(45.f).getNormal<float>() == p45.getNormalized());
    EXPECT_TRUE(rot(135.f).getNormal<float>() == p135.getNormalized());
    EXPECT_TRUE(rot(225.f).getNormal<float>() == p225.getNormalized());
    EXPECT_TRUE(rot(315.f).getNormal<float>() == p315.getNormalized());

    EXPECT_TRUE(rot(p45.getNormalized()).getAngle360() == 45.f);
    EXPECT_TRUE(rot(p135.getNormalized()).getAngle360() == 135.f);
    EXPECT_TRUE(rot(p225.getNormalized()).getAngle360() == 225.f);
    EXPECT_TRUE(rot(p315.getNormalized()).getAngle360() == 315.f);
}

TEST(rotator2, comparison)
{
    EXPECT_NE(rot(45), rot(-315));
    EXPECT_TRUE(rot(45).doesAngleEqual(rot(-315)));

    EXPECT_NE(rot(135), rot(-225));
    EXPECT_TRUE(rot(135).doesAngleEqual(rot(-225)));

    EXPECT_NE(rot(225), rot(-135));
    EXPECT_TRUE(rot(225).doesAngleEqual(rot(-135)));

    EXPECT_NE(rot(315), rot(-45));
    EXPECT_TRUE(rot(315).doesAngleEqual(rot(-45)));
}
