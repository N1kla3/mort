#include <cstdint>
#include "core.h"
#include "gtest/gtest.h"
#include "vec3.hpp"

using vec = mort::Vector3<float>;
using veci = mort::Vector3<int32_t>;
using vecd = mort::Vector3<double>;

TEST(vector3, basicf)
{
    vec first;
    first.x = 4.f;
    vec second;
    second = vec(5.f, 5.f, 6.f);

    auto res = first - second;

    EXPECT_EQ(res.x, -1.f);

    EXPECT_TRUE(sizeof(mort::Vector3<float>) == 3 * sizeof(float));
    EXPECT_TRUE(sizeof(mort::Vector3<int32_t>) == 3 * sizeof(int32_t));
    EXPECT_TRUE(sizeof(mort::Vector3<double>) == 3 * sizeof(double));

    veci b;
    veci c;
    veci d = b + c;
    EXPECT_EQ(d, veci(0));
}

TEST(vector3, normalizationf)
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

TEST(vector3, normalizationi)
{
    veci tonorm(5, 9, 11);
    tonorm.normalize();
    EXPECT_EQ(tonorm.len(), 0);
    EXPECT_EQ(tonorm.lenSqr(), 0);

    // big number
    tonorm = veci(13424, 54034, 910213);
    tonorm.normalize();
    EXPECT_EQ(tonorm.len(), 0);
    EXPECT_EQ(tonorm.lenSqr(), 0);

    tonorm = veci(100, 0, 0);
    tonorm.normalize();
    EXPECT_EQ(tonorm.len(), 0);
    EXPECT_EQ(tonorm.lenSqr(), 0);
}

TEST(vector3, normalizationd)
{
    vecd tonorm(5.5f, 9.3f, 11.7f);
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.0));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.0));

    // big number
    tonorm = vecd(13424.34, 54034.4545, 910213.589);
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.0));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.0));

    // small number
    tonorm = vecd(0.00134244, 0.0005445, 0.00009109);
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.0));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.0));
}

TEST(vector3, dotproductf)
{
    vec a(10.5f, 0.f, 0.f);
    vec b(0.f, 10.5f, 0.f);

    float res = 0.f;
    float c = a.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = vec::dotProduct(a, b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = vec::dotProduct(b, a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, b.lenSqr()));

    res = 110.25f;
    b = a;
    c = a.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = vec::dotProduct(a, b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = vec::dotProduct(b, a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, b.lenSqr()));

    res = 0.5f;
    b.y = sqrtf(21.f * 21.f - 10.5f * 10.5f);
    a.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(a.len(), 1.f));
    b.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(b.len(), 1.f));

    EXPECT_TRUE(mort::isNearlyEqual(vec::dotProduct(a, b), 0.5f));
}

TEST(vector3, dotproductd)
{
    vecd a(10.5, 0.0, 0.0);
    vecd b(0.0, 10.5, 0.0);

    double res = 0.0;
    double c = a.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = vecd::dotProduct(a, b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = vecd::dotProduct(b, a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, b.lenSqr()));

    res = 110.25;
    b = a;
    c = a.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = vecd::dotProduct(a, b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = vecd::dotProduct(b, a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, b.lenSqr()));

    res = 0.5;
    b.y = sqrtf(21. * 21. - 10.5 * 10.5);
    a.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(a.len(), 1.0));
    b.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(b.len(), 1.0));

    EXPECT_TRUE(mort::isNearlyEqual(vecd::dotProduct(a, b), 0.5f));
}

TEST(vector3, dotproducti)
{
    veci a(10, 0.0, 0.0);
    veci b(0.0, 10, 0.0);

    double res = 0.0;
    double c = a.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = veci::dotProduct(a, b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = veci::dotProduct(b, a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(b);
    EXPECT_EQ(static_cast<int32_t>(c), b.lenSqr());

    res = 100.0;
    b = a;
    c = a.dot(b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = veci::dotProduct(a, b);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = veci::dotProduct(b, a);
    EXPECT_TRUE(mort::isNearlyEqual(c, res));
    c = b.dot(b);
    EXPECT_EQ(static_cast<int32_t>(c), b.lenSqr());
}
