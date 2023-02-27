#pragma once

#include "Pokemon.h"

#include <vector>

class Trainer;

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

    PokemonPtr recup(std::string name, Trainer &trainer)
    {
        auto it = _pokemons.begin();

        for (; it != _pokemons.end(); it++)
        {
            if ((*it)->name() == name && (*it)->trainer() == &trainer)
            {
                PokemonPtr res = std::move(*it);
                _pokemons.erase(it);
                return res;
            }
        }
        return nullptr;
    }

private:
    std::vector<PokemonPtr> _pokemons;
};