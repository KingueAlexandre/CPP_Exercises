#pragma once
#include <string>
#include "Pokemon.h"

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    Pokeball()
    {
        _pokemon = nullptr;
    }

    bool empty() const
    {
        return _pokemon == nullptr;
    }

    void store(PokemonPtr poke)
    {
        _pokemon = std::move(poke);
    }

    const Pokemon &pokemon() const
    {
        return *_pokemon;
    }

    PokemonPtr steal()
    {
        return std::move(_pokemon);
    }

private:
    PokemonPtr _pokemon;
};
