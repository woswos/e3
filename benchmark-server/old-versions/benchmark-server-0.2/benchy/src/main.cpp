#include <iostream>

#include "gate.h"
#include "encrypt.h"
#include "decrypt.h"

using std::cout;
using std::endl;

int main()
{

    Benchy* scheme;

    scheme -> gate_operation();
/*
    Bit a0(true);
    Bit b0(false);
    Bit r0(false);



    //b->gate_and(a0, b0, r0);
    cout << r0.value << endl;
*/
    delete scheme;

    return 0;
}
