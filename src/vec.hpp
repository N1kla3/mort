#pragma once
#include <array>
#include <stddef.h>

namespace mort
{
    template<typename T>
    concept number = std::is_arithmetic_v<T>;

    template<number T, size_t N>
    class BaseVector
    {
    protected:
        std::array<T, N> m_Data;

    public:
        using type = std::decay_t<T>;
        using own_type = BaseVector<type, N>;

        BaseVector()
        {
            m_Data.fill(0);
        };
        BaseVector(const BaseVector& vec) = default;
        BaseVector(BaseVector&& vec) = default;
        BaseVector& operator=(const BaseVector& vec) = default;
        BaseVector& operator=(BaseVector&& vec) = default;
        ~BaseVector() = default;

        type operator[](size_t index) const
        {
            return m_Data[index];
        }
        type& operator[](size_t index)
        {
            return m_Data[index];
        }

        template<size_t Index>
            requires(Index < N && Index >= 0)
        type getByIndex() const
        {
            return m_Data[Index];
        }
        template<size_t Index>
            requires(Index < N && Index >= 0)
        type& getByIndex()
        {
            return m_Data[Index];
        }

        friend BaseVector<T, N> operator+(const BaseVector<T, N>& lhs, const BaseVector<T, N>& rhs)
        {
            BaseVector<T, N> vec;
            for (size_t idx = 0; idx < N; idx++)
            {
                vec[idx] = lhs[idx] + rhs[idx];
            }
            return vec;
        }
        friend BaseVector<T, N> operator-(const BaseVector<T, N>& lhs, const BaseVector<T, N>& rhs)
        {
            BaseVector<T, N> vec;
            for (size_t idx = 0; idx < N; idx++)
            {
                vec[idx] = lhs[idx] - rhs[idx];
            }
            return vec;
        }
    };
} // namespace mort
