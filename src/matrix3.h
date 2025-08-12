#pragma once

#include <algorithm>
#include <cassert>
#include "core.h"

namespace mort
{

    template<floating T>
    class Matrix3 final
    {
    private:
        constexpr static size_t arr_size = 9;

    public:
        Matrix3() {}
        Matrix3(T i1, T i2, T i3, T j1, T j2, T j3, T k1, T k2, T k3)
        {
            i[0] = i1;
            i[1] = i2;
            i[2] = i3;

            j[0] = j1;
            j[1] = j2;
            j[2] = j3;

            k[0] = k1;
            k[1] = k2;
            k[2] = k3;
        }
        Matrix3(const Matrix3& other)
        {
            std::copy(other.arr, other.arr + arr_size, arr);
        }
        Matrix3(Matrix3&& other) noexcept
        {
            std::copy(other.arr, other.arr + arr_size, arr);
        }
        Matrix3& operator=(const Matrix3& other)
        {
            std::copy(other.arr, other.arr + arr_size, arr);
            return *this;
        }
        Matrix3& operator=(Matrix3&& other) noexcept
        {
            std::copy(other.arr, other.arr + arr_size, arr);
            return *this;
        }

        friend bool operator==(const Matrix3& lhs, const Matrix3& rhs)
        {
            bool res = true;
            for (size_t i = 0; i < arr_size; i++)
            {
                res &= isNearlyEqual(lhs.arr[i], rhs.arr[i]);
            }
            return res;
        }
        friend bool operator!=(const Matrix3& lhs, const Matrix3& rhs)
        {
            return !(lhs == rhs);
        }


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


        // Methods//
        // =======//
        T getVal(size_t row, size_t column) const
        {
            size_t index = (row * 3) + column;
            assert(index < 9);
            return arr[index];
        }
        T& getVal(size_t row, size_t column)
        {
            size_t index = (row * 3) + column;
            assert(index < 9);
            return arr[index];
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
            T arr[arr_size];
        };
    };
} // namespace mort
