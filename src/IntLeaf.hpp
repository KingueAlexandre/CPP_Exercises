#pragma once

#include "Leaf.hpp"


class IntLeaf : public Leaf
{
public:
    IntLeaf(int init) : _value{init}{};

    int data() const{
        return _value;
    }

    NodeKind kind(){
        return NodeKind::INT;
    }

    virtual std::string print(){
        return std::to_string(_value);
    }

private:
    int _value;
};