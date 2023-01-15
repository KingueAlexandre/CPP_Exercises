#include <iostream>
#include <string>

int main()
{
    std::string var;
    std::cout << "What's your name?" << std::endl;
    std::cin >> var;
    std::cout << "Hello " << var << "!" << std::endl;

    return 0;
}
/*
Le type permettant de représenter une chaîne de caractère est le type std::string.
*/
