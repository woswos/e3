#include <iostream>
#include <fstream>

#include "oleg.h"

using std::string;
using std::cout;

using Bit = CiphertextBit;


string f2s(string n){ string r; std::ifstream(n)>>r; return r; }

int main(int argc, char const * argv[])
try
{

    Bit a(f2s("const1")), b(f2s("const0"));

    auto c = gate_nand(a, b);

    cout << "a = " << a.str() << '\n';
    cout << "b = " << b.str() << '\n';
    cout << "c = " << c.str() << '\n';

    return 0;
}
catch(...)
{
    cout<<"Exception\n";
    return 1;
}
