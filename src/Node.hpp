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
public:
    virtual std::string print() const { return "Node"; }

    virtual void push_back(std::unique_ptr<Node> node) { node = nullptr; }

    virtual int child_count() { return 0; }

    virtual ~Node() = default;

private:
};

using NodePtr = std::unique_ptr<Node>;