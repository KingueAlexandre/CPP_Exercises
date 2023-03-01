#pragma once

#include "Leaf.hpp"

class StringLeaf : public Leaf
{
public:
    StringLeaf(std::string init)
        : _value { init } {};

    std::string data() const { return _value; }

    NodeKind kind() { return NodeKind::STRING; }

    virtual std::string print() const override { return "\"" + _value + "\""; }

    static NodePtr make_ptr(std::string val) { return std::make_unique<StringLeaf>(val); }

private:
    std::string _value;
};