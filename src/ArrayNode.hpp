#pragma once

#include "Node.hpp"

class ArrayNode : public Node
{
public:
    NodeKind kind() { return NodeKind::ARRAY; }

    virtual std::string print() const override
    {
        std::string res = "[";
        for (auto& elem : _array)
        {
            res += elem->print();
        }
        return res += "]";
    }

    int child_count() { return _array.size(); }

    static NodePtr make_ptr() { return std::make_unique<ArrayNode>(); }

    void push_back(NodePtr node) override { _array.push_back(node); }

private:
    // std::array<Node> _array;
    std::vector<NodePtr> _array;
};