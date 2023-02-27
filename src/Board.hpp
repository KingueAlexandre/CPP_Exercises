#pragma once

#include "Card.hpp"

#include <map>
#include <vector>
#include <memory>

class Board
{
public:
    bool put(std::unique_ptr<Card> card)
    {
        if (_board[(*card).get_type()].size() < 5)
        {
            if (((*card).get_type() == CardType::Spell || (*card).get_type() == CardType::Trap) && (_board[CardType::Trap].size() + _board[CardType::Spell].size() >= 5))
            {
                return false;
            }
            _board[(*card).get_type()].emplace_back(std::move(card));
            return true;
        }
        return false;
    }

private:
    std::map<CardType, std::vector<std::unique_ptr<Card>>> _board;
};
