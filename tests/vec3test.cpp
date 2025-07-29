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

    veci b(5, 0, 5);
    veci c(5, 5, 0);
    veci d = b + c;
    EXPECT_EQ(d, veci(10, 5, 5));

    EXPECT_EQ(veci(1, 1, 0), c / 5);
}

TEST(vector3, basicoperationf)
{
    vec a(5.f, 6.f, 9.f);
    vec b(5.f, 6.f, 9.f);

    // multiplication
    vec res(25.f, 36.f, 81.f);
    EXPECT_EQ(a * b, res);
    vec c = a;
    c *= b;
    EXPECT_EQ(c, res);
    EXPECT_EQ(vec(10.f, 12.f, 18.f), 2 * a);
    EXPECT_EQ(vec(10.f, 12.f, 18.f), a * 2);
    vec temp_m = a;
    temp_m *= 2;
    EXPECT_EQ(vec(10.f, 12.f, 18.f), temp_m);

    // division
    EXPECT_EQ(res / b, a);
    c = res;
    c /= b;
    EXPECT_EQ(c, a);
    EXPECT_EQ(vec(2.5f, 3.f, 4.5f), c / 2);
    vec temp_d = c;
    temp_d /= 2;
    EXPECT_EQ(vec(2.5f, 3.f, 4.5f), temp_d);

    // addition
    res = vec(10.f, 12.f, 18.f);
    EXPECT_EQ(a + b, res);
    c = a;
    c += b;
    EXPECT_EQ(c, res);

    // substraction
    res = vec(10.f, 12.f, 18.f);
    EXPECT_EQ(res - b, a);
    c = res;
    c -= b;
    EXPECT_EQ(c, a);
}

TEST(vector3, basicoperationd)
{
    vecd a(5.0, 6.0, 9.0);
    vecd b(5.0, 6.0, 9.0);

    // multiplication
    vecd res(25.0, 36.0, 81.0);
    EXPECT_EQ(a * b, res);
    vecd c = a;
    c *= b;
    EXPECT_EQ(c, res);
    EXPECT_EQ(vecd(10.0, 12.0, 18.0), 2 * a);
    EXPECT_EQ(vecd(10.0, 12.0, 18.0), a * 2);
    vecd temp_m = a;
    temp_m *= 2;
    EXPECT_EQ(vecd(10.0, 12.0, 18.0), temp_m);

    // division
    EXPECT_EQ(res / b, a);
    c = res;
    c /= b;
    EXPECT_EQ(c, a);
    EXPECT_EQ(vecd(2.5, 3.0, 4.5), c / 2);
    vecd temp_d = c;
    temp_d /= 2;
    EXPECT_EQ(vecd(2.5f, 3.f, 4.5f), temp_d);

    // addition
    res = vecd(10.0, 12.0, 18.0);
    EXPECT_EQ(a + b, res);
    c = a;
    c += b;
    EXPECT_EQ(c, res);

    // substraction
    res = vecd(10.0, 12.0, 18.0);
    EXPECT_EQ(res - b, a);
    c = res;
    c -= b;
    EXPECT_EQ(c, a);
}

TEST(vector3, basicoperationi)
{
    veci a(5, 6, 9);
    veci b(5, 6, 9);

    // multiplication
    veci res(25, 36, 81);
    EXPECT_EQ(a * b, res);
    veci c = a;
    c *= b;
    EXPECT_EQ(c, res);
    EXPECT_EQ(veci(10, 12, 18), 2 * a);
    EXPECT_EQ(veci(10, 12, 18), a * 2);
    veci temp_m = a;
    temp_m *= 2;
    EXPECT_EQ(veci(10, 12, 18), temp_m);

    // division
    EXPECT_EQ(res / b, a);
    c = res;
    c /= b;
    EXPECT_EQ(c, a);
    EXPECT_EQ(veci(2, 3, 4), c / 2);
    veci temp_d = c;
    temp_d /= 2;
    EXPECT_EQ(veci(2, 3, 4), temp_d);

    // addition
    res = veci(10, 12, 18);
    EXPECT_EQ(a + b, res);
    c = a;
    c += b;
    EXPECT_EQ(c, res);

    // substraction
    res = veci(10, 12, 18);
    EXPECT_EQ(res - b, a);
    c = res;
    c -= b;
    EXPECT_EQ(c, a);
}

TEST(vector3, normalizationf)
{
    vec tonorm(5.5f, 9.3f, 11.7f);
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().lenSqr(), 1.f));
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.f));

    // big number
    tonorm = vec(13424.34f, 54034.4545f, 910213.589f);
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().lenSqr(), 1.f));
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.f));

    // small number
    tonorm = vec(0.00134244f, 0.0005445f, 0.00009109f);
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().lenSqr(), 1.f));
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.f));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.f));
}

TEST(vector3, normalizationi)
{
    veci tonorm(5, 9, 11);
    EXPECT_EQ(tonorm.getNormalized().len(), 0);
    EXPECT_EQ(tonorm.getNormalized().lenSqr(), 0);
    tonorm.normalize();
    EXPECT_EQ(tonorm.len(), 0);
    EXPECT_EQ(tonorm.lenSqr(), 0);

    // big number
    tonorm = veci(13424, 54034, 910213);
    EXPECT_EQ(tonorm.getNormalized().len(), 0);
    EXPECT_EQ(tonorm.getNormalized().lenSqr(), 0);
    tonorm.normalize();
    EXPECT_EQ(tonorm.len(), 0);
    EXPECT_EQ(tonorm.lenSqr(), 0);

    tonorm = veci(100, 0, 0);
    EXPECT_EQ(tonorm.getNormalized().len(), 0);
    EXPECT_EQ(tonorm.getNormalized().lenSqr(), 0);
    tonorm.normalize();
    EXPECT_EQ(tonorm.len(), 0);
    EXPECT_EQ(tonorm.lenSqr(), 0);
}

TEST(vector3, normalizationd)
{
    vecd tonorm(5.5f, 9.3f, 11.7f);
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().len(), 1.0));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().lenSqr(), 1.0));
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.0));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.0));

    // big number
    tonorm = vecd(13424.34, 54034.4545, 910213.589);
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().len(), 1.0));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().lenSqr(), 1.0));
    tonorm.normalize();
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.len(), 1.0));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.lenSqr(), 1.0));

    // small number
    tonorm = vecd(0.00134244, 0.0005445, 0.00009109);
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().len(), 1.0));
    EXPECT_TRUE(mort::isNearlyEqual(tonorm.getNormalized().lenSqr(), 1.0));
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

TEST(vector3, crossproductf)
{
    vec a(10.f, 0.0f, 0.0f);
    vec b(0.0f, 10.f, 0.0f);

    EXPECT_EQ(a.cross(b), vec(0, 0, 100.f));
    EXPECT_EQ(b.cross(a), vec(0, 0, -100.f));

    EXPECT_EQ(a.cross(b).dot(b), 0.f);
    EXPECT_EQ(a.cross(b).dot(a), 0.f);
    EXPECT_EQ(b.cross(a).dot(b), 0.f);
    EXPECT_EQ(b.cross(a).dot(a), 0.f);


    EXPECT_EQ(vec::crossProduct(a, b), vec(0, 0, 100.f));
    EXPECT_EQ(vec::crossProduct(b, a), vec(0, 0, -100.f));

    EXPECT_EQ(vec::crossProduct(a, b).dot(b), 0.f);
    EXPECT_EQ(vec::crossProduct(a, b).dot(a), 0.f);
    EXPECT_EQ(vec::crossProduct(b, a).dot(b), 0.f);
    EXPECT_EQ(vec::crossProduct(b, a).dot(a), 0.f);
}

TEST(vector3, crossproductd)
{
    vecd a(10.0, 0.0, 0.0);
    vecd b(0.0, 10.0, 0.0);

    EXPECT_EQ(a.cross(b), vecd(0, 0, 100.0));
    EXPECT_EQ(b.cross(a), vecd(0, 0, -100.0));

    EXPECT_EQ(a.cross(b).dot(b), 0.0);
    EXPECT_EQ(a.cross(b).dot(a), 0.0);
    EXPECT_EQ(b.cross(a).dot(b), 0.0);
    EXPECT_EQ(b.cross(a).dot(a), 0.0);


    EXPECT_EQ(vecd::crossProduct(a, b), vecd(0, 0, 100.0));
    EXPECT_EQ(vecd::crossProduct(b, a), vecd(0, 0, -100.0));

    EXPECT_EQ(vecd::crossProduct(a, b).dot(b), 0.0);
    EXPECT_EQ(vecd::crossProduct(a, b).dot(a), 0.0);
    EXPECT_EQ(vecd::crossProduct(b, a).dot(b), 0.0);
    EXPECT_EQ(vecd::crossProduct(b, a).dot(a), 0.0);
}

TEST(vector3, crossproducti)
{
    veci a(10, 0, 0);
    veci b(0, 10, 0);

    EXPECT_EQ(a.cross(b), veci(0, 0, 100));
    EXPECT_EQ(b.cross(a), veci(0, 0, -100));

    EXPECT_EQ(a.cross(b).dot(b), 0);
    EXPECT_EQ(a.cross(b).dot(a), 0);
    EXPECT_EQ(b.cross(a).dot(b), 0);
    EXPECT_EQ(b.cross(a).dot(a), 0);


    EXPECT_EQ(veci::crossProduct(a, b), veci(0, 0, 100));
    EXPECT_EQ(veci::crossProduct(b, a), veci(0, 0, -100));

    EXPECT_EQ(veci::crossProduct(a, b).dot(b), 0);
    EXPECT_EQ(veci::crossProduct(a, b).dot(a), 0);
    EXPECT_EQ(veci::crossProduct(b, a).dot(b), 0);
    EXPECT_EQ(veci::crossProduct(b, a).dot(a), 0);
}
