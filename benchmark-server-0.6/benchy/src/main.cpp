#include <iostream>

#include "gate.h"

using std::cout;
using std::endl;

int main()
{
    GateApi* tfhe = new GateApi();

    tfhe->benchmark();

    return 0;
}
