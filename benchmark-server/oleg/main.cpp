#include <iostream>

#include "oleg.h"


using Bit = CiphertextBit;

int main(int argc, char const * argv[])
{

    Bit a("2"), b("1");

    auto c = gate_nand(a, b);

    std::cout << c.str() << '\n';

    return 0;
}
