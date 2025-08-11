#pragma once

#include <algorithm>
namespace mort
{
    template<typename T>
    class Matrix3 final
    {
    public:
        Matrix3() {}
        Matrix3(const Matrix3& other)
        {
            std::copy(other.arr, other.arr + 9, arr);
        }
        Matrix3(Matrix3&& other) noexcept
        {
            std::copy(other.arr, other.arr + 9, arr);
        }
        Matrix3& operator=(const Matrix3& other)
        {
            std::copy(other.arr, other.arr + 9, arr);
            return *this;
        }
        Matrix3& operator=(Matrix3&& other) noexcept
        {
            std::copy(other.arr, other.arr + 9, arr);
            return *this;
        }


        // Methods//
        // =======//
        friend Matrix3 operator*(const Matrix3& lhs, const Matrix3& rhs)
        {
            Matrix3 res = lhs;
            res *= rhs;
            return res;
        }

        Matrix3& operator*=(const Matrix3& rhs)
        {
            Matrix3 res;
            res.i[0] = i[0] * rhs.i[0] + i[1] * rhs.j[0] + i[2] * rhs.k[0];
            res.i[1] = i[0] * rhs.i[1] + i[1] * rhs.j[1] + i[2] * rhs.k[1];
            res.i[2] = i[0] * rhs.i[2] + i[1] * rhs.j[2] + i[2] * rhs.k[2];

            res.j[0] = j[0] * rhs.i[0] + j[1] * rhs.j[0] + j[2] * rhs.k[0];
            res.j[1] = j[0] * rhs.i[1] + j[1] * rhs.j[1] + j[2] * rhs.k[1];
            res.j[2] = j[0] * rhs.i[2] + j[1] * rhs.j[2] + j[2] * rhs.k[2];

            res.k[0] = k[0] * rhs.i[0] + k[1] * rhs.j[0] + k[2] * rhs.k[0];
            res.k[1] = k[0] * rhs.i[1] + k[1] * rhs.j[1] + k[2] * rhs.k[1];
            res.k[2] = k[0] * rhs.i[2] + k[1] * rhs.j[2] + k[2] * rhs.k[2];

            *this = res;
            return *this;
        }

    private:
        union
        {
            struct
            {
                T i[3];
                T j[3];
                T k[3];
            };
            T arr[9];
        };
    };
} // namespace mort
