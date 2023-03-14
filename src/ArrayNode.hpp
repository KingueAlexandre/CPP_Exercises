#pragma once

#include "Node.hpp"

class ArrayNode : public Node
{
public:
    NodeKind    kind() { return NodeKind::ARRAY; }
    std::string print() const override;

    // std::string print() const
    // {
    //     std::string res = "[";
    //     for (auto& elem : _array)
    //     {
    //         res += std::move(elem->print());
    //     }
    //     return res += "]";
    // }

    int child_count() { return _array.size(); }

    static std::unique_ptr<ArrayNode> make_ptr(std::vector<NodePtr> _array = {});

    void push_back(NodePtr node);

    size_t child_count() { return _array.size(); }

private:
    // std::array<Node> _array;
    std::vector<NodePtr> _array;
};