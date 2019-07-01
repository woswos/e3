#include <iostream>

#include "oleg.h"


using Bit = CiphertextBit;

int main(int argc, char const * argv[])
{

    Bit a("1"), b("0");

    auto c = gate_nand(a, b);

    std::cout << c.str() << '\n';

    return 0;
}
