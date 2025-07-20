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
    struct Vector2
    {
        union
        {
            struct
            {
                T x;
                T y;
            };

            std::array<T, 2> xy;
        };

    public:
        using type = std::decay_t<T>;

        constexpr Vector2()
            : xy{0} {};
        constexpr explicit Vector2(T value)
            : xy{value, value}
        {
        }
        constexpr Vector2(T x, T y)
            : xy{x, y}
        {
        }
        constexpr Vector2(const Vector2& vec) noexcept = default;
        constexpr Vector2(Vector2&& vec) noexcept = default;
        constexpr Vector2& operator=(const Vector2& vec) noexcept = default;
        constexpr Vector2& operator=(Vector2&& vec) noexcept = default;
        constexpr ~Vector2() noexcept = default;

        type operator[](size_t index) const
        {
            return xy[index];
        }
        type& operator[](size_t index)
        {
            return xy[index];
        }

        template<size_t Index>
            requires(Index < 3)
        constexpr type index() const
        {
            return xy[Index];
        }
        template<size_t Index>
            requires(Index < 3)
        constexpr type& index()
        {
            return xy[Index];
        }

        constexpr type len() const noexcept
        {
            return std::sqrt((x * x) + (y * y));
        }

        constexpr type lenSqr() const noexcept
        {
            return (x * x) + (y * y);
        }

        // for int vector result will be 0 vector
        constexpr void normalize()
        {
            if constexpr (std::is_floating_point_v<type>)
            {
                type l = len();
                if (mort::isNearlyZero(l))
                {
                    x = y = 0.0;
                    return;
                }
                else
                {
                    x /= l;
                    y /= l;
                }
            }
            else
            {
                x = y = 0;
            }
        }

        float dot(const Vector2& rhs) const
        {
            return ((double) x * rhs.x) + ((double) y * rhs.y);
        }

        static float dotProduct(const Vector2<T>& lhs, const Vector2<T>& rhs);

        // OPERATORS //
        friend constexpr bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            if constexpr (std::is_floating_point_v<type>)
            {
                return mort::isNearlyEqual(lhs.x, rhs.x) && mort::isNearlyEqual(lhs.y, rhs.y);
            }
            return lhs.x == rhs.x && lhs.y == rhs.y;
        }
        friend constexpr bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            return !(lhs == rhs);
        }

        friend constexpr bool operator<(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            if (lhs.x == rhs.x)
            {
                return lhs.y < rhs.y;
            }
            return lhs.x < rhs.x;
        }
        friend constexpr bool operator>(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            return rhs < lhs;
        }
        friend constexpr bool operator<=(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            return !(lhs > rhs);
        }
        friend constexpr bool operator>=(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            return !(lhs < rhs);
        }

        constexpr Vector2<T> operator+=(const Vector2<T>& rhs) noexcept
        {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }
        constexpr Vector2<T> operator-=(const Vector2<T>& rhs) noexcept
        {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }
        constexpr Vector2<T> operator*=(const Vector2<T>& rhs) noexcept
        {
            x *= rhs.x;
            y *= rhs.y;
            return *this;
        }
        constexpr Vector2<T> operator/=(const Vector2<T>& rhs) noexcept
        {
            x /= rhs.x;
            y /= rhs.y;
            return *this;
        }

        friend constexpr Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            Vector2<T> vec;
            vec.x = lhs.x + rhs.x;
            vec.y = lhs.y + rhs.y;
            return vec;
        }
        friend constexpr Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            Vector2<T> vec;
            vec.x = lhs.x - rhs.x;
            vec.y = lhs.y - rhs.y;
            return vec;
        }
        friend constexpr Vector2<T> operator*(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            Vector2<T> vec;
            vec.x = lhs.x * rhs.x;
            vec.y = lhs.y * rhs.y;
            return vec;
        }
        friend constexpr Vector2<T> operator/(const Vector2<T>& lhs, const Vector2<T>& rhs) noexcept
        {
            Vector2<T> vec;
            vec.x = lhs.x / rhs.x;
            vec.y = lhs.y / rhs.y;
            return vec;
        }

        // STATIC //
    };

    template<number T>
    float Vector2<T>::dotProduct(const Vector2<T>& lhs, const Vector2<T>& rhs)
    {
        return lhs.dot(rhs);
    }
} // namespace mort
