#pragma once

template <unsigned i>
constexpr unsigned fibonacci()
{
    if constexpr (i < 2)
        return 1;
    else
        return fibonacci<i - 1>() + fibonacci<i - 2>();
}