#pragma once

#include <cmath>
#include <concepts>
#include <limits>
#include <stdint.h>

namespace mort
{
    template<typename T>
    concept number = std::is_arithmetic_v<T>;

    template<typename FloatingPoint>
        requires std::floating_point<FloatingPoint>
    [[nodiscard]] constexpr bool isNearlyZero(FloatingPoint numb,
                                              FloatingPoint tolerance = std::numeric_limits<FloatingPoint>::epsilon())
    {
        return (std::fabs(numb) <= tolerance);
    }

    template<typename FloatingPoint>
        requires std::floating_point<FloatingPoint>
    [[nodiscard]] constexpr bool isNearlyEqual(FloatingPoint lhs,
                                               FloatingPoint rhs,
                                               FloatingPoint tolerance = std::numeric_limits<FloatingPoint>::epsilon())
    {
        FloatingPoint diff = std::fabs(lhs - rhs);
        return ((diff <= tolerance) || (diff < std::fmax(std::fabs(lhs), std::fabs(rhs)) * tolerance));
    }

    template<typename FloatingPoint>
        requires std::floating_point<FloatingPoint>
    [[nodiscard]] constexpr bool isEqualWithPrecision(FloatingPoint lhs, FloatingPoint rhs, uint8_t stepSize = 1u)
    {
        FloatingPoint min_lhs =
                lhs - ((lhs - std::nextafter(lhs, std::numeric_limits<FloatingPoint>::lowest())) * stepSize);
        FloatingPoint max_lhs =
                lhs + ((std::nextafter(lhs, std::numeric_limits<FloatingPoint>::max()) - lhs) * stepSize);

        return min_lhs <= rhs && max_lhs >= rhs;
    }


}; // namespace mort
