#pragma once

class Plush
{
public:
    Plush (const int& cost): _cost { cost }{
    }

    Plush (){
        _cost = 10;
    }

    int get_cost() const{
        return _cost;
    }
    void set_cost(int new_cost){
        _cost = new_cost;
    }
private:
    int _cost = 10;

};