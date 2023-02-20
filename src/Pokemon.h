#pragma once

#include <memory>
#include <string>

// A creature that is cute and can fight other ones.

class Pokemon
{
public:
    Pokemon(std ::string name) : _name{name}, _id{ID++}
    {
    }

    Pokemon(const Pokemon &other) : _name{other.name()}, _id{ID++}
    {
    }

    Pokemon &operator=(const Pokemon &other)
    {
        if (this != &other)
        {
            _name = other.name();
        }

        return *this;
    }

    std::string name() const
    {
        return _name;
    }

    int id() const
    {
        return _id;
    }

private:
    static inline int ID = 0;

    std::string _name;
    const int _id;
};

using PokemonPtr = std::unique_ptr<Pokemon>;
