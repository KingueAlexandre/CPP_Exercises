#pragma once

#include "Node.hpp"

class ArrayNode : public Node
{
public:
    NodeKind kind() { return NodeKind::ARRAY; }

    virtual std::string print() const override
    {
        std::string res = "[";
        for (auto elem : _array)
        {
            res += elem.print();
        }
        return res += "]";
    }

private:
    // std::array<Node> _array;
    std::vector<Node> _array;
};