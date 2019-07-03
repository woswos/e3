#include <iostream>

#include "gate-api.h"

using std::cout;
using std::endl;

int main()
{
    GateApi* barkin = new GateApi();

    barkin->setupPtr = barkin->setup();

    barkin->bobKeyPtr = barkin->generateBobKey(barkin->setupPtr);

    barkin->aliceKeyPtr = barkin->generateAliceKey();


    cout << barkin->aliceKeyPtr << endl << endl;



    void *ptr = 0;

    //barkin->encrypt(1);

    //barkin->decrypt(ptr);


    return 0;
}
