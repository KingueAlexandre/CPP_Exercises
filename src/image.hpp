#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>


template <typename P, size_t W, size_t H>
class Image{

public:
    // Image(const std::function<P(const size_t i, const size_t j)> & functor)
    // {
    //     for (size_t j = 0; j < H; ++j)
    //     {
    //         for (size_t i = 0; i < W; ++i)
    //         {
    //             _screen[j][i] = functor(j,i);
    //         }
    //     }
    // }

    Image(const std::function<P(const size_t, const size_t)> & functor)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                (*this)(i,j) = functor(i,j);
            }
        }        
    }

    Image(const P& def) : _default {def}{
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                _screen[j][i] = def;
            }
        }
    }

    Image() = default;

    P& operator()(const size_t i, const size_t j){
        return _screen[j][i];
    }

     const P& operator()(const size_t i, const size_t j) const{
        return _screen[j][i];
    }

    

private:
    P _default;
    std::array<std::array<P, W>, H> _screen;
    // const std::function<P(const size_t, const size_t)> & _functor;
};

template<typename A, typename B, size_t W, size_t H>
Image<A, W, H> operator+(const Image<A,W,H> & lhs, const Image<B,W,H> & rhs)
{
    Image<A, W, H> out = {};
    for (size_t j = 0; j < H; ++j)
    {
        for (size_t i = 0; i < W; ++i)
        {
            out(i,j) = lhs(i,j) + rhs(i,j);
        }
    }
    return out;
}