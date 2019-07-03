#include "scheme-base.h"
#include <iostream>

#include <helib/FHE.h>
#include <helib/EncryptedArray.h>

void* Scheme::init(){

    // Plaintext prime modulus
    unsigned long p = 4999;
    // Cyclotomic polynomial - defines phi(m)
    unsigned long m = 32109;
    // Hensel lifting (default = 1)
    unsigned long r = 1;
    // Number of bits of the modulus chain
    unsigned long bits = 300;
    // Number of columns of Key-Switching matix (default = 2 or 3)
    unsigned long c = 2;

    std::cout << "Initialising context object..." << std::endl;

    // Intialise context
    FHEcontext context(m, p, r);

    // Modify the context, adding primes to the modulus chain
    std::cout  << "Building modulus chain..." << std::endl;
    buildModChain(context, bits, c);


    // Transfer object to heap from stack
    FHEcontext *FHEcontextPtr = new FHEcontext(context);

    // Cast to void pointer for returning back to main
    void  *ptr = static_cast<void*>(FHEcontextPtr);

    return ptr;
}

void* Scheme::generateBobKey(void *setupPtr){

    // Cast void pointer to data type pointer
    FHEcontext  *contextPtr = static_cast<FHEcontext*>(setupPtr);

    //FHEcontext *FHEcontextPtr = new FHEcontext(context);

    //FHEcontext context = (FHEcontext*)&contextPtr;
    // Print the context
    contextPtr->zMStar.printout();
    //std::cout << std::endl;

    // Secret key management
    std::cout << "Creating secret key..." << std::endl;
    // Create a secret key associated with the context
    FHESecKey secret_key(contextPtr);


    void  *ptr = 0;

    return ptr;
}

void* Scheme::generateAliceKey(void *setupPtr){




    void  *ptr = 0;

    return ptr;
}

void* Scheme::getAliceKey(){


    void  *ptr = 0;

    return ptr;
}


void* Scheme::encrypt(void* message){

    void  *ptr = 0;

    return ptr;
}


void* Scheme::decrypt(void* cipherText){

    void  *ptr = 0;

    return ptr;
}


void Scheme::cleanup(){


}
