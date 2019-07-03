#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::cout;
using std::string;

int main(int ac, const char * av[])
try
{
    if ( ac < 2 ) throw "Usage: gen, enc, dec\n";

    string cmd = av[1];

    if (0) {}

    else if ( cmd == "gen" )
    {
        unsigned k = unsigned(std::time(0)) % 10;
        std::ofstream("priv.key") << k << '\n';
        std::ofstream("eval.key") << k << '\n';
        std::ofstream("const0") << k << '\n';
        std::ofstream("const1") << (1 + k) << '\n';
    }

    else if ( cmd == "enc" || cmd == "dec" )
    {
        if ( ac < 3 ) throw "Need arg";
        int ar = std::stoi(av[2]);

        unsigned k = 0;
        std::ifstream in("priv.key");
        if ( !in ) throw "Cannot open priv.key";
        in >> k;

        if ( cmd == "enc" ) ar += k;
        else ar -= k;
        cout << ar << '\n';
    }

    else throw "Wrong command";
}

catch (const char * e)
{
    cout << "Error: " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "Exception\n";
    return 1;
}
