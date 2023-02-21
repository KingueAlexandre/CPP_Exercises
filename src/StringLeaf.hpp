#pragma once

#include "Leaf.hpp"

class StringLeaf : public Leaf
{
public:
    StringLeaf(std::string init)
        : _value { init } {};

    std::string data() const { return _value; }

    NodeKind kind() { return NodeKind::STRING; }

    virtual std::string print() override { return "\"" + _value + "\""; }

private:
    std::string _value;
};