#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <array>
#include <iostream>
#include <string>
#include <vector>

class Node : public InstanceCounter
{
public:
    std::string print() { return "Node"; }

private:
};