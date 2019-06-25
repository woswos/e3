#include <iostream>

#include "gate-api.h"

using std::cout;
using std::endl;

int main()
{
    GateApi* tfhe = new GateApi();

    tfhe->parametersPtr = tfhe->init();

    tfhe->keySetPtr = tfhe->generateKeySet(tfhe->parametersPtr);

    void *cipherText1 = tfhe->encrypt(1);

    void *cipherText2 = tfhe->encrypt(1);



    void *result = tfhe->gate_and(cipherText1, cipherText2, tfhe->keySetPtr);

    tfhe->message = tfhe->decrypt(result);



    cout << tfhe->message << "\n";


    void *ptr = 0;

    //barkin->encrypt(1);

    //barkin->decrypt(ptr);


    return 0;
}
