#include <iostream>

#include "gate.h"
#include "arithmetic.h"

using std::cout;
using std::endl;

int main()
{
    GateApi* tfhe = new GateApi();

    tfhe->benchmark();

    //ArithmeticApi* HElib = new ArithmeticApi();

    //HElib->benchmark();

    return 0;
}
