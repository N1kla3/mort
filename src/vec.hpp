#pragma once
#include <array>

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

        BaseVector() = default;

        type operator[](size_t index) const
        {
            return m_Data[index];
        }
        type& operator[](size_t index)
        {
            return m_Data[index];
        }

        template<size_t Index>
            requires(Index < N && Index > 0)
        type getByIndex() const
        {
            return m_Data[Index];
        }
        template<size_t Index>
            requires(Index < N && Index > 0)
        type& getByIndex()
        {
            return m_Data[Index];
        }
    };

    template<number T, size_t N>
    class Vector : public BaseVector<T, N>
    {
    };

    template<number T>
    class Vector<T, 2> : public BaseVector<T, 2>
    {
    };

    template<number T>
    class Vector<T, 3> : public BaseVector<T, 3>
    {
    };

    template<number T>
    class Vector<T, 4> : public BaseVector<T, 4>
    {
    };
} // namespace mort
