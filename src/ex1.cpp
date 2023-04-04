#include "ex1.hpp"

void pairwise_concatenate(std::list<std::list<int>>& list1, const std::list<std::list<int>>& list2)
{

    // for (auto& elem : list1)
    // {
    //     concatenate(elem, list2.(list1.indexOf(elem)))
    // }

    auto it  = list1.begin();
    auto it2 = list2.begin();

    while (it != list1.end() && it2 != list2.end())
    {
        // it.push_back(it2);
        concatenate(*it, *it2);
        it++;
        it2++;
    }
}

void pairwise_concatenate(std::list<std::list<int>>& list1, const std::list<std::list<int>>&& list2)
{

    // for (auto& elem : list1)
    // {
    //     concatenate(elem, list2.(list1.indexOf(elem)))
    // }

    auto it  = list1.begin();
    auto it2 = list2.begin();

    while (it != list1.end() && it2 != list2.end())
    {
        // it.push_back(it2);
        concatenate(*it, *it2);
        it++;
        it2++;
    }
}