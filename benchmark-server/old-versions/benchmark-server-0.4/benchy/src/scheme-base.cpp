#include "scheme-base.h"
#include <iostream>

#include <helib/FHE.h>
#include <helib/EncryptedArray.h>

void Scheme::init(){

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
    //FHEcontext *FHEcontextPtr = new FHEcontext(context);


    //initParams<FHEcontext>* params = new initParams<FHEcontext>;
    // params->setupPtr = new FHEcontext(context);

    initParams<FHEcontext> params;
    params.setupPtr = new FHEcontext(context);

}

void Scheme::generateBobKey(){


    // Print the context
    Scheme::initParams<FHEcontext>::setupPtr->zMStar.printout();


    std::cout << std::endl;


}

void Scheme::generateAliceKey(){



}

void Scheme::getAliceKey(){



}


void Scheme::encrypt(){


}


void Scheme::decrypt(){


}


void Scheme::cleanup(){


}
