#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Kid
{
public:
    Kid(const std::string &name, int money) : _name{name}, _money{money}
    {
    }
    std ::string get_name() const
    {
        return _name;
    }
    int get_money() const
    {
        return _money;
    }
    friend std::ostream &operator<<(std::ostream &out, const Kid &kid);

private:
    std::string _name;
    int _money;
};

std::ostream &operator<<(std::ostream &out, const Kid &kid)
{
    out << kid.get_name() << " has " << kid.get_money() << " euros.";
    return out;
}