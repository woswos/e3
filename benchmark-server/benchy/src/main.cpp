#include <iostream>

#include "gate.h"
#include "arithmetic.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {

    #ifndef GATEAPI
        ArithmeticApi* scheme = new ArithmeticApi();
    #else
        GateApi* scheme = new GateApi();
    #endif

    scheme->benchmark();

    delete scheme;

    return 0;
}
