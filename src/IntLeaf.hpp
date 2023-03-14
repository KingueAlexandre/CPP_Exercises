#pragma once

#include "Leaf.hpp"

class IntLeaf : public Leaf
{
public:
    IntLeaf(int init)
        : Leaf { NodeKind::STRING }
        , _value { init } {};

    int data() const { return _value; }

    NodeKind kind() { return NodeKind::INT; }

    std::string print() const override { return std::to_string(_value); }

    static NodePtr make_ptr(int val) { return std::make_unique<IntLeaf>(val); }

private:
    int _value;
};