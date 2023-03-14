#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Node : public InstanceCounter
{
protected:
    Node(NodeKind kind)
        : _kind(kind)
    {}

public:
    virtual std::string print() const = 0;

    virtual void push_back(std::unique_ptr<Node> node) { node = nullptr; }

    virtual size_t child_count() { return 0; }

    virtual ~Node() = default;

private:
    const NodeKind _kind;
};

using NodePtr = std::unique_ptr<Node>;