#pragma once

#include "Card.hpp"

enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field,
};

std::string_view to_string(SpellType spell)
{
    switch (spell)
    {
    case SpellType::Normal:
        return "Normal";
    case SpellType::Equip:
        return "Equip";
    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";

    default:
        return "";
    }
}

class Spell : public Card
{
public:
    Spell(std::string id, std::string name, SpellType spelltype)
        : Card{id, CardType::Spell}, _spell_type{spelltype}
    {
        this->set_name(name);
        _symbol = u8"魔";
    }

    SpellType get_spell_type() const
    {
        return _spell_type;
    }

private:
    SpellType _spell_type;
};