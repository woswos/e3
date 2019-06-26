#include "scheme-base.h"
#include <iostream>

#include <helib/FHE.h>
#include <helib/EncryptedArray.h>

void* Scheme::setup(){

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
    void *FHEcontextPtr = new FHEcontext(context);

    return FHEcontextPtr;
}

void* Scheme::generateBobKey(void *setupPtr){


    std::cout  << "deniyom" << std::endl;

    // Recover context from the pointer
    //FHEcontext context = static_cast<FHEcontext>(*setupPtr);

    //FHEcontext *context = dynamic_cast<FHEcontext>(&setupPtr);



std::cout  << "oldu" << std::endl;

    // Print the context
    &setupPtr.zMStar.printout();
    std::cout << std::endl;

std::cout  << "olcak" << std::endl;

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


void* Scheme::encrypt(int message){

    void  *ptr = 0;

    return ptr;
}


int Scheme::decrypt(void* cipherText){

    int message = 1;

    return message;
}


void Scheme::cleanup(){


}
