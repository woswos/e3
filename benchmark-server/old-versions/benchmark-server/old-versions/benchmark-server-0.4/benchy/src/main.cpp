#include <iostream>

#include "gate-api.h"

using std::cout;
using std::endl;

int main()
{
    GateApi* barkin = new GateApi();


    int x = 5;

    int *ptr = &x;

    barkin->init();

    barkin->generateBobKey();


    //barkin->encrypt(1);

    //barkin->decrypt(ptr);


    return 0;
}
