#pragma once
#include "PC.h"
#include "Pokeball.h"
#include <array>

// A person that captures Pokemons and makes them fight.
class Trainer
{

public:
    Trainer(const std::string &name, PC &pc) : _name{name}, _pc{pc}
    {
    }

    const std::string &name() const
    {
        return _name;
    }

    const std::array<Pokeball, 6u> &pokeballs() const
    {
        return _pokeballs;
    }

    void capture(PokemonPtr poke)
    {
        Pokeball ball = Pokeball{};
        ball.store(std::move(poke));
        if (_pokeballs.size() != 6u)
        {
            _pokeballs[nb_balls] = ball;
        }
        nb_balls += 1;
    }

private:
    int nb_balls = 0;
    std::string _name;
    PC &_pc;
    std::array<Pokeball, 6u> _pokeballs;
};
