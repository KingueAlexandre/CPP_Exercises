#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

std::set<std::string> make_exit_commands()
{
    std::set<std::string> res;
    res.emplace("q");
    res.emplace("quit");
    res.emplace("e");
    res.emplace("end");
    return res;
}

void command_add(std::istream &flux, std::map<std::string, std::string> &maptranslate, std::vector<std::pair<std::string, std::string>> &history)
{
    std::string w1;
    std::string w2;
    flux >> w1;
    flux >> w2;
    std::cout << w1 << " => " << w2 << std::endl;
    maptranslate.insert({w1, w2});
    history.emplace_back(w1, w2);
}

void command_translate(std::istream &flux, std::map<std::string, std::string> maptranslate)
{
    std::string w1;
    std::string w2;
    std::getline(flux, w1);
    std::stringstream line(w1);
    while (line >> w2)
    {

        if (maptranslate.count(w2) > 0)
        {
            auto tmp = maptranslate.find(w2);
            std::cout << tmp->second << std::endl;
        }
        else
        {
            std::cout << "???" << std::endl;
        }
    }
}

void command_print(std::map<std::string, std::string> maptranslate)
{
    for (auto elem : maptranslate)
    {
        std::cout << elem.first << " => " << elem.second << std::endl;
    }
}

void command_save(std::istream &flux, std::vector<std::pair<std::string, std::string>> history)
{
    std::string w1;
    std::ofstream fichier;
    flux >> w1;
    fichier.open(w1, std::ios::out);
    if (fichier.bad())
    {
        return;
    }
    for (auto elem : history)
    {
        fichier << "add " << elem.first << " " << elem.second << std::endl;
    }

    fichier.close();
}

void command_clear(std::map<std::string, std::string> &maptranslate, std::vector<std::pair<std::string, std::string>> &history)
{
    maptranslate.clear();
    history.clear();
}

void command_remove(std::istream &flux, std::map<std::string, std::string> &maptranslate)
{
    std::string w1;
    flux >> w1;

    auto it = maptranslate.begin();

    for (; it != maptranslate.end(); ++it)
    {
        if (it->first == w1 || it->second == w1)
        {
            maptranslate.erase(it);
        }
    }
}

int boucle_principal(std::string var, std::istream &flux, std::map<std::string, std::string> &maptranslate, std::vector<std::pair<std::string, std::string>> &history)
{
    int res = 0;
    std::string w1;
    std::set<std::string> setstop = make_exit_commands();

    if (var == "add")
    {
        command_add(flux, maptranslate, history);
    }
    else if (var == "translate")
    {
        command_translate(flux, maptranslate);
    }
    else if (var == "print")
    {
        command_print(maptranslate);
    }
    else if (var == "save")
    {
        command_save(flux, history);
    }
    else if (var == "load")
    {
        flux >> w1;
        std::ifstream flux2(w1);

        if (flux2)
        {
            while (flux2 >> w1)
            {
                res = boucle_principal(w1, flux2, maptranslate, history);
                if (res == -1)
                {
                    break;
                }
            }
        }
    }
    else if (setstop.count(var))
    {
        return -1;
    }
    else if (var == "clear")
    {
        command_clear(maptranslate, history);
    }
    else if (var == "remove")
    {
        command_remove(flux, maptranslate);
    }
    return 1;
}

int main(int argc, char const *argv[])
{

    std::string source;
    std::string cible;
    std::string w1;
    std::string var;
    std::map<std::string, std::string> maptranslate;
    std::vector<std::pair<std::string, std::string>> history;
    std::ofstream fichier;

    std::cout << argc << " : " << argv[0] << std::endl;

    if (argc < 2)
    {
        source = "fr";
        cible = "en";
    }
    else if (argc < 3)
    {
        source = argv[1];
        cible = "en";
    }
    else
    {
        source = argv[1];
        cible = argv[2];
    }

    std::cout << source << " : " << cible << std::endl;

    while (true)
    {
        std::cin >> var;
        if (var == "load")
        {
            std::cin >> w1;
            std::ifstream flux(w1);

            if (flux)
            {
                while (flux >> w1)
                {
                    if (boucle_principal(w1, flux, maptranslate, history) == -1)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            if (boucle_principal(var, std::cin, maptranslate, history) == -1)
            {
                break;
            }
        }
    }

    return 0;
}