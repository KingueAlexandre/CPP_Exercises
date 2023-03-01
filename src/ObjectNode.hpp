#pragma once

#include "Node.hpp"

class ObjectNode : public Node
{
public:
    NodeKind kind() { return NodeKind::OBJECT; }

    virtual std::string print() const override
    {
        std::string res = "{";
        for (auto elem : _array)
        {
            res += elem.print();
        }
        return res += "}";
    }

    static NodePtr make_ptr() { return std::make_unique<ObjectNode>(); }

private:
    // std::array<Node> _array;
    std::vector<Node> _array;
};