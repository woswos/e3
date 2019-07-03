#include <iostream>

#include "gate.h"
#include "arithmetic.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {

    #ifndef GATEAPI
        ArithmeticApi* scheme = new ArithmeticApi();
        scheme->benchmark(scheme);

    #else
        GateApi* scheme = new GateApi();
        scheme->benchmark(scheme);

    #endif

    // Delete pointers allocated in heap
    //scheme->DeleteParameters();

    delete scheme;

    return 0;
}
