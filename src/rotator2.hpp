#pragma once
#include <cmath>
#include "core.h"
#include "vec2.hpp"

namespace mort
{

    class Rotator2
    {
    public:
        constexpr Rotator2() noexcept
            : m_Angle(0.f)
        {
        }
        explicit constexpr Rotator2(float inAngle) noexcept
            : m_Angle(inAngle)
        {
        }
        template<typename T>
        explicit constexpr Rotator2(mort::Vector2<T> vec) noexcept
        {
            m_Angle = std::atan2(vec.y, vec.x) * (static_cast<T>(180) / M_PI);
        }

        template<typename T>
        mort::Vector2<T> getNormal() const
        {
            float rad = m_Angle * (M_PI / static_cast<T>(180));
            return mort::Vector2<T>(std::cos(rad), std::sin(rad));
        }

        // METHODS
        constexpr bool doesAngleEqual(Rotator2 another) const
        {
            float a = std::fmod(m_Angle, 360.f);
            a = a < 0 ? a + 360.f : a;
            float b = std::fmod(another.m_Angle, 360.f);
            b = b < 0 ? b + 360.f : b;
            return mort::isNearlyEqual(a, b);
        }

        constexpr float getAngle() const noexcept
        {
            return m_Angle;
        }
        constexpr float getAngle360() const noexcept
        {
            float a = std::fmod(m_Angle, 360.f);
            a = a < 0 ? a + 360.f : a;
            return a;
        }

        // COMPARISON
        friend constexpr bool operator==(Rotator2 lhs, Rotator2 rhs) noexcept
        {
            return mort::isNearlyEqual(lhs.m_Angle, rhs.m_Angle);
        }
        friend constexpr bool operator!=(Rotator2 lhs, Rotator2 rhs) noexcept
        {
            return !mort::isNearlyEqual(lhs.m_Angle, rhs.m_Angle);
        }
        friend constexpr bool operator<(Rotator2 lhs, Rotator2 rhs) noexcept
        {
            return lhs.m_Angle < rhs.m_Angle;
        }
        friend constexpr bool operator<=(Rotator2 lhs, Rotator2 rhs) noexcept
        {
            return lhs.m_Angle <= rhs.m_Angle;
        }
        friend constexpr bool operator>(Rotator2 lhs, Rotator2 rhs) noexcept
        {
            return lhs.m_Angle > rhs.m_Angle;
        }
        friend constexpr bool operator>=(Rotator2 lhs, Rotator2 rhs) noexcept
        {
            return lhs.m_Angle >= rhs.m_Angle;
        }

        // ARITHMETIC
        friend constexpr Rotator2 operator+(Rotator2 lhs, Rotator2 rhs) noexcept
        {
            return Rotator2(lhs.m_Angle + rhs.m_Angle);
        }
        friend constexpr Rotator2 operator-(Rotator2 lhs, Rotator2 rhs) noexcept
        {
            return Rotator2(lhs.m_Angle - rhs.m_Angle);
        }
        constexpr Rotator2& operator+=(Rotator2 rhs) noexcept
        {
            m_Angle = m_Angle + rhs.m_Angle;
            return *this;
        }
        constexpr Rotator2& operator-=(Rotator2 rhs) noexcept
        {
            m_Angle = m_Angle - rhs.m_Angle;
            return *this;
        }

        template<number T>
        constexpr Rotator2 operator*(T numb)
        {
            return Rotator2(m_Angle * numb);
        }
        template<number T>
        friend constexpr Rotator2 operator*(T numb, Rotator2 rhs)
        {
            return Rotator2(rhs.m_Angle * numb);
        }
        template<number T>
        constexpr Rotator2 operator/(T numb)
        {
            return Rotator2(m_Angle / numb);
        }
        template<number T>
        constexpr Rotator2& operator*=(T numb)
        {
            m_Angle = m_Angle * numb;
            return *this;
        }
        template<number T>
        constexpr Rotator2& operator/=(T numb)
        {
            m_Angle = m_Angle / numb;
            return *this;
        }


    private:
        float m_Angle;
    };
} // namespace mort
