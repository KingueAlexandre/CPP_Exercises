#pragma once
#include <string>
#include <vector>

class PlushStore
{
public:
    PlushStore(const std::string &name) : _name{name}
    {
    }

    PlushStore()
    {
        _name = "";
    }

    std::string get_name() const
    {
        return _name;
    }
    void set_name(std::string new_name)
    {
        _name = new_name;
    }
    int get_wealth_amount() const
    {
        return _wealth_amount;
    }
    int get_stock_size() const
    {
        return _stock_size;
    }
    void loan(int wealth)
    {
        _wealth_amount += wealth;
    }
    int get_debt_amount()
    {
        return _wealth_amount + _wealth_amount / 10;
    }
    int make_plush(int plush)
    {
        if (_wealth_amount == 0)
        {
            return plush + this->get_experience();
        }
        else if (_wealth_amount - plush < 0)
        {
            _stock_size += 1;
            _wealth_amount = 0;
        }
        else
        {
            _stock_size += 1;
            _wealth_amount -= plush;
        }
        history.emplace_back(plush);
        return plush + this->get_experience();
    }

    int get_experience() const
    {
        return history.size();
    }

private:
    std::string _name;
    int _wealth_amount = 0;
    int _stock_size = 0;
    std::vector<int> history;
};