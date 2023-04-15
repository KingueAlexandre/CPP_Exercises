#pragma once

#include <iterator>
#include <type_traits>

template <unsigned i>
constexpr unsigned fibonacci()
{
    if constexpr (i < 2)
        return 1;
    else
        return fibonacci<i - 1>() + fibonacci<i - 2>();
}

template <typename T1, typename T2>
constexpr bool content_of_same_type()
{
    return std::is_same<typename T1::value_type, typename T2::value_type>::value;
}

template <typename T1, typename T2>
void add_all(T1& t1, const T2& t2)
{
    if constexpr (content_of_same_type<T1, T2>())
    {
        for (auto it = t2.begin(); it != t2.end(); it++)
        {
            t1.emplace_back(*it);
        }
    }
}

template <typename T>
constexpr bool has_random_access()
{
    return std::is_same<std::random_access_iterator_tag,
                        typename std::iterator_traits<typename T::iterator>::iterator_category>::value;
}

template <typename T>
int access(T const& container, unsigned i)
{
    if constexpr (has_random_access<T>() == true)
    {
        return container[i];
    }
    else
    {
        auto it = container.begin();
        while (i != 0 && it != container.end())
        {
            it++;
            i -= 1;
        }
        return *it;
    }
}