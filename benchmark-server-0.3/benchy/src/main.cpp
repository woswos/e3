#include <iostream>

#include "gate-api.h"
#include "seal/seal.h"

using std::cout;
using std::endl;

int main()
{
    GateApi* barkin = new GateApi();




    barkin->bobKeyPtr = barkin->generateBobKey();



/*
    barkin->aliceKeyPtr = barkin->getAliceKey();


    cout << barkin->aliceKeyPtr << endl << endl;
*/


    void *ptr = 0;

    //barkin->encrypt(1);

    //barkin->decrypt(ptr);


    return 0;
}
