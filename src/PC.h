#pragma once

#include "Pokemon.h"

#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    const std::vector<PokemonPtr> &pokemons()
    {
        return _pokemons;
    }

    void transfer(PokemonPtr poke)
    {
        if (poke != nullptr)
        {
            _pokemons.push_back(std::move(poke));
        }
    }

private:
    std::vector<PokemonPtr> _pokemons;
};