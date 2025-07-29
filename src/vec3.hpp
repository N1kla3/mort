#pragma once
#include <array>
#include <cmath>
#include <type_traits>
#include "core.h"

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

        constexpr Vector3()
            : xyz{0} {};
        constexpr explicit Vector3(T value)
            : xyz{value, value, value}
        {
        }
        constexpr Vector3(T x, T y, T z)
            : xyz{x, y, z}
        {
        }
        constexpr Vector3(const Vector3& vec) noexcept = default;
        constexpr Vector3(Vector3&& vec) noexcept = default;
        constexpr Vector3& operator=(const Vector3& vec) noexcept = default;
        constexpr Vector3& operator=(Vector3&& vec) noexcept = default;
        constexpr ~Vector3() noexcept = default;

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
        constexpr type index() const
        {
            return xyz[Index];
        }
        template<size_t Index>
            requires(Index < 3)
        constexpr type& index()
        {
            return xyz[Index];
        }

        constexpr type len() const noexcept
        {
            return std::sqrt((x * x) + (y * y) + (z * z));
        }

        constexpr type lenSqr() const noexcept
        {
            return (x * x) + (y * y) + (z * z);
        }

        // for int vector result will be 0 vector
        constexpr void normalize()
        {
            if constexpr (std::is_floating_point_v<type>)
            {
                type l = len();
                if (mort::isNearlyZero(l))
                {
                    x = y = z = 0.0;
                    return;
                }
                else
                {
                    x /= l;
                    y /= l;
                    z /= l;
                }
            }
            else
            {
                x = y = z = 0;
            }
        }

        constexpr Vector3 getNormalized() const
        {
            Vector3 result{0};
            if constexpr (std::is_floating_point_v<type>)
            {
                type l = len();
                if (!mort::isNearlyZero(l))
                {
                    result.x = x / l;
                    result.y = y / l;
                    result.z = z / l;
                }
            }
            return result;
        }

        float dot(const Vector3& rhs) const
        {
            return ((double) x * rhs.x) + ((double) y * rhs.y) + ((double) z * rhs.z);
        }

        Vector3 cross(const Vector3& rhs) const
        {
            Vector3 res;
            res.x = y * rhs.z - z * rhs.y;
            res.y = z * rhs.x - x * rhs.z;
            res.z = x * rhs.y - y * rhs.x;
            return res;
        }

        static float dotProduct(const Vector3<T>& lhs, const Vector3<T>& rhs);
        static Vector3 crossProduct(const Vector3& lhs, const Vector3& rhs);

        // OPERATORS //
        friend constexpr bool operator==(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            if constexpr (std::is_floating_point_v<type>)
            {
                return mort::isNearlyEqual(lhs.x, rhs.x) && mort::isNearlyEqual(lhs.y, rhs.y) &&
                       mort::isNearlyEqual(lhs.z, rhs.z);
            }
            return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
        }
        friend constexpr bool operator!=(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            return !(lhs == rhs);
        }

        friend constexpr bool operator<(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            if (lhs.x == rhs.x)
            {
                if (lhs.y == rhs.y)
                {
                    return lhs.z < rhs.z;
                }
            }
            return lhs.x < rhs.x;
        }
        friend constexpr bool operator>(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            return rhs < lhs;
        }
        friend constexpr bool operator<=(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            return !(lhs > rhs);
        }
        friend constexpr bool operator>=(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            return !(lhs < rhs);
        }

        // Scalar Begin
        constexpr Vector3<T> operator*=(T rhs) noexcept
        {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }
        constexpr Vector3<T> operator/=(T rhs) noexcept
        {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            return *this;
        }

        friend constexpr Vector3<T> operator*(T lhs, const Vector3<T>& rhs) noexcept
        {
            Vector3<T> vec(lhs);
            vec *= rhs;
            return vec;
        }

        constexpr Vector3<T> operator*(T lhs) noexcept
        {
            Vector3<T> vec(*this);
            vec *= lhs;
            return vec;
        }
        constexpr Vector3<T> operator/(T lhs) noexcept
        {
            Vector3<T> vec(*this);
            vec /= lhs;
            return vec;
        }
        // Scalar End

        constexpr Vector3<T> operator+=(const Vector3<T>& rhs) noexcept
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            return *this;
        }
        constexpr Vector3<T> operator-=(const Vector3<T>& rhs) noexcept
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            return *this;
        }
        constexpr Vector3<T> operator*=(const Vector3<T>& rhs) noexcept
        {
            x *= rhs.x;
            y *= rhs.y;
            z *= rhs.z;
            return *this;
        }
        constexpr Vector3<T> operator/=(const Vector3<T>& rhs) noexcept
        {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            return *this;
        }

        friend constexpr Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            Vector3<T> vec(lhs);
            vec += rhs;
            return vec;
        }
        friend constexpr Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            Vector3<T> vec(lhs);
            vec -= rhs;
            return vec;
        }
        friend constexpr Vector3<T> operator*(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            Vector3<T> vec(lhs);
            vec *= rhs;
            return vec;
        }
        friend constexpr Vector3<T> operator/(const Vector3<T>& lhs, const Vector3<T>& rhs) noexcept
        {
            Vector3<T> vec(lhs);
            vec /= rhs;
            return vec;
        }

        // STATIC //
    };

    template<number T>
    float Vector3<T>::dotProduct(const Vector3<T>& lhs, const Vector3<T>& rhs)
    {
        return lhs.dot(rhs);
    }

    template<number T>
    Vector3<T> Vector3<T>::crossProduct(const Vector3& lhs, const Vector3& rhs)
    {
        return lhs.cross(rhs);
    }
} // namespace mort
