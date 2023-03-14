#pragma once

#include "Node.hpp"

class ObjectNode : public Node
{
public:
    NodeKind    kind() { return NodeKind::OBJECT; }
    std::string print() const override;

    // std::string print() const
    // {
    //     std::string res = "{";
    //     for (auto& elem : _array)
    //     {
    //         res += elem->print();
    //     }
    //     return res += "}";
    // }

    static std::unique_ptr<ArrayNode> make_ptr(std::vector<NodePtr> _array = {});

    void push_back(NodePtr node);

    size_t child_count() { return _array.size(); }

private:
    // std::array<Node> _array;
    std::vector<NodePtr> _array;
};