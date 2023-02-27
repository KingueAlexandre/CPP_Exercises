#pragma once

#include "Card.hpp"

enum class TrapType
{
    Normal,
    Continuous,
    Counter,
};

std::string_view to_string(TrapType spell)
{
    switch (spell)
    {
    case TrapType::Normal:
        return "Normal";
    case TrapType::Counter:
        return "Counter";
    case TrapType::Continuous:
        return "Continuous";
    default:
        return "";
    }
}

class Trap : public Card
{
public:
    Trap(std::string id, std::string name, TrapType traptype)
        : Card{id, CardType::Trap}, _trap_type{traptype}
    {
        this->set_name(name);
        _symbol = u8"罠";
    }

    TrapType get_trap_type() const
    {
        return _trap_type;
    }

private:
    TrapType _trap_type;
};