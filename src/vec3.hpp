#pragma once
#include <array>
#include <cmath>

namespace mort
{
    template<typename T>
    concept number = std::is_arithmetic_v<T>;

    template<number T>
    struct Vector3
    {
        union
        {
            struct
            {
                T x;
                T y;
                T z;
            };

            std::array<T, 3> xyz;
        };

    public:
        using type = std::decay_t<T>;

        Vector3()
            : xyz(0) {};
        Vector3(T x, T y, T z)
        {
            xyz = {x, y, z};
        }
        Vector3(const Vector3& vec) = default;
        Vector3(Vector3&& vec) = default;
        Vector3& operator=(const Vector3& vec) = default;
        Vector3& operator=(Vector3&& vec) = default;
        ~Vector3() = default;

        type operator[](size_t index) const
        {
            return xyz[index];
        }
        type& operator[](size_t index)
        {
            return xyz[index];
        }

        template<size_t Index>
            requires(Index < 3)
        type index() const
        {
            return xyz[Index];
        }
        template<size_t Index>
            requires(Index < 3)
        type& index()
        {
            return xyz[Index];
        }

        T len() const
        {
            return std::sqrt((x * x) + (y * y) + (z * z));
        }

        T lenSqr() const
        {
            return (x * x) + (y * y) + (z * z);
        }

        friend Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs)
        {
            Vector3<T> vec;
            for (size_t idx = 0; idx < 3; idx++)
            {
                vec[idx] = lhs[idx] + rhs[idx];
            }
            return vec;
        }
        friend Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs)
        {
            Vector3<T> vec;
            for (size_t idx = 0; idx < 3; idx++)
            {
                vec[idx] = lhs[idx] - rhs[idx];
            }
            return vec;
        }
    };
} // namespace mort
