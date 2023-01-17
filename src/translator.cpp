#include <iostream>
#include <set>
#include <map>

std::set<std::string> make_exit_commands()
{
    std::set<std::string> res;
    res.emplace("q");
    res.emplace("quit");
    res.emplace("e");
    res.emplace("end");
    return res;
}

int main()
{
    std::string var;
    std::set<std::string> setstop = make_exit_commands();
    std::map<std::string, std::string> maptranslate;
    std::string w1;
    std::string w2;
    while (true)
    {
        std::cin >> var;
        if (var == "add")
        {

            std::cin >> w1;
            std::cin >> w2;
            std::cout << w1 << " => " << w2 << std::endl;
            maptranslate.insert({w1, w2});
        }

        if (var == "translate")
        {
            std::cin >> w1;
            if (maptranslate.count(w1) > 0)
            {
                auto tmp = maptranslate.find(w1);
                std::cout << tmp->second << std::endl;
            }
            else
            {
                std::cout << "???" << std::endl;
            }
        }

        // std::getline(std::cin, var);

        if (setstop.count(var))
        {
            break;
        }
    }

    return 0;
}