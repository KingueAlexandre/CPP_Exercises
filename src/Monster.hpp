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

class Monster : public Card
{
public:
    Monster(const std::string& id, const std::string &name, const Attribute& attr, std::string monster_type,const int& atk, const int& def) : Card{id, CardType::Monster}, _attribute{attr}, _atk{atk}, _def{def}, _monster_type{monster_type}
    {
        set_name(name);
    }

    Attribute get_attribute() const
    {
        return _attribute;
    }

    int get_atk() const
    {
        return _atk;
    }

    int get_def() const
    {
        return _def;
    }

private:
    Attribute _attribute;
    int _atk;
    int _def;
    std::string _monster_type;
};