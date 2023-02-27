#pragma once

#include "Card.hpp"

#include <string>
#include <string_view>
#include <utility>

enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind,
};

std::string_view
to_symbol(const Attribute attr)
{
    switch (attr)
    {
    case Attribute::Dark:
        return u8"闇";
    case Attribute::Divine:
        return u8"神";
    case Attribute::Earth:
        return u8"地";
    case Attribute::Fire:
        return u8"炎";
    case Attribute::Light:
        return u8"光";
    case Attribute::Water:
        return u8"水";
    case Attribute::Wind:
        return u8"風";
    default:
        return "";
    }
}

class Monster : public Card
{
public:
    Monster(std::string id, std::string name, Attribute attr, std::string monster_type, int atk, int def)
        : Card{std::move(id), CardType::Monster},
          _attribute{attr},
          _monster_type{std::move(monster_type)},
          _atk{atk},
          _def{def}
    {
        set_name(std::move(name));
        _symbol = to_symbol(_attribute);
    }

    // Monster(std::string id, std::string name, Attribute attribute, std::string monster_type, int atk, int def)
    //     : Card{std::move(id), CardType::Monster},
    //       _attribute{attribute},
    //       _monster_type{std::move(monster_type)},
    //       _atk{atk},
    //       _def{def}
    // {
    //     set_name(std::move(name));
    //     _symbol = to_symbol(_attribute);
    // }

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

    std::string get_description() const
    {

        return "[" + _monster_type + "]\n" + Card::get_description() + "\nATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def) + "";
    }

    std::string_view get_symbol() const
    {
        return _symbol;
    }

private:
    Attribute _attribute = {};
    std::string _monster_type;
    int _atk = 0;
    int _def = 0;
};