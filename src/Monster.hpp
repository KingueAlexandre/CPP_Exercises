#pragma once

#include <string>

#include <Card.hpp>

enum Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind
};

std::string
to_symbol(Attribute attr)
{
    switch (attr)
    {
    case Dark:
        return u8"闇";
    case Divine:
        return u8"神";
    case Earth:
        return u8"地";
    case Fire:
        return u8"炎";
    case Light:
        return u8"光";
    case Water:
        return u8"水";
    case Wind:
        return u8"風";
    default:
        return "";
    }
}

class Monster
{
public:
    Monster(std::string id, std::string name, Attribute attr, std::string monster_type, int _atk, int _def) : _card{Card{id, Monster}}, _attribute{attr}, _atk{atk}, _def{def}, _monster_type{monster_type}
    {
        _card.set_name(name);
    }

private:
    Card _card;
    Attribute _attribute;
    int _atk;
    int _def;
    std::string _monster_type;
};