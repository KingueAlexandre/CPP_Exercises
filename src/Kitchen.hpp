#pragma once
#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"

#include <algorithm>
#include <list>
#include <memory>
#include <vector>

class Kitchen
{
public:
    const Unit& register_unit(const Unit val)
    {
        lst_unit.emplace_back(std::move(val));
        return lst_unit.back();
    }

    const Unit* find_unit(const std::string& val)
    {
        for (auto it = lst_unit.begin(); it != lst_unit.end(); it++)
        {
            if ((*it).name == val)
            {
                return &(*it);
            }
        }
        return nullptr;
    }

    const Ingredient& register_ingredient(const Ingredient val)
    {
        lst_ingre.emplace_back(std::move(val));
        return lst_ingre.back();
    }

    const Ingredient* find_ingredient(const std::string& val)
    {
        for (auto it = lst_ingre.begin(); it != lst_ingre.end(); it++)
        {
            if ((*it).name == val)
            {
                return &(*it);
            }
        }
        return nullptr;
    }

private:
    // std::vector<std::unique_ptr<Unit>> lst;
    std::list<Unit>       lst_unit;
    std::list<Ingredient> lst_ingre;
};
