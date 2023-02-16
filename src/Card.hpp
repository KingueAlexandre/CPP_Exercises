#pragma once

#include <string>

enum CardType
{
    None,
    Monster,
    Spell,
    Trap
};

std::string
to_string(CardType card)
{
    switch (card)
    {
    case None:
        return "None";
    case Trap:
        return "Trap";
    case Spell:
        return "Spell";
    case Monster:
        return "Monster";
    default:
        return "";
    }
}

class Card
{
public:
    explicit Card(std::string id, CardType card) : _id{id}, _type{card}
    {
        _name = "";
        _description = "";
    }

    std::string get_id() const
    {
        return _id;
    }

    CardType get_type() const
    {
        return _type;
    }

    std::string get_name() const
    {
        return _name;
    }

    std::string get_description() const
    {
        return _description;
    }

    void set_name(std::string name)
    {
        _name = name;
    }

    void set_description(std::string description)
    {
        _description = description;
    }

private:
    std::string _id;
    CardType _type;
    std::string _name;
    std::string _description;
};
