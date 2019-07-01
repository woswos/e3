#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::cout;
using std::string;

int main(int ac, const char * av[])
{
    if ( ac < 2 )
    {
        cout << "Use: gen, enc, dec\n";
        return 0;
    }

    string cmd = av[1];

    if (0) {}

    else if ( cmd == "gen" )
    {
        unsigned k = unsigned(std::time(0)) % 10;
        std::ofstream("priv.key") << k << '\n';
        std::ofstream("eval.key") << k << '\n';
    }

    else
    {
        cout << "Wrong command\n";
        return 1;
    }
}
