#include <cstdint>
#include "core.h"
#include "gtest/gtest.h"
#include "matrix3.hpp"

TEST(matrix3, base)
{
    mort::Matrix3<float> mat;
    mort::Matrix3<float> mat1;
    mat1 = mat;
}
