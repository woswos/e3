#include "scheme-base.h"
#include <iostream>
#include <map>
#include <time.h>
#include <random>
#include <functional>

#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>

void Scheme::base_benchmark(){

    Scheme::init();

    Scheme::generateKeySet();

}

void Scheme::init(){

    // generate default gate bootstrapping parameters
    int32_t minimum_lambda = 100;
    TFheGateBootstrappingParameterSet *params = new_default_gate_bootstrapping_parameters(minimum_lambda);

    Scheme::storeParameter("params", params);

}

void Scheme::generateKeySet(){

    // cast back to data type from void
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    TFheGateBootstrappingSecretKeySet *keyset = new_random_gate_bootstrapping_secret_keyset(params);

    Scheme::storeParameter("keyset", keyset);

}


void* Scheme::encrypt(int message){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    // generate a new unititialized ciphertext
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    // encrypts a boolean
    bootsSymEncrypt(result, message, keyset);

    return static_cast<void*>(result);

}


int Scheme::decrypt(void* cipherText){

    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));

    // Cast back to data type from void
    LweSample  *cipherTextPtr = static_cast<LweSample*>(cipherText);

    /** decrypts a boolean */
    return bootsSymDecrypt(cipherTextPtr, keyset);
}

void Scheme::cleanup(){

}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template <typename T>
void Scheme::storeParameter(string key, T* pointer){

    void *ptr = static_cast<void*>(pointer);
    Scheme::parameters.insert({key, ptr});

}


void* Scheme::getParameter(string key){

    return Scheme::parameters[key];
}




void Scheme::addTiming(string key, long int value){
    if ( Scheme::timings.find(key) == Scheme::timings.end() ) {
        Scheme::timings.insert({key, value});

    } else {
        long int temp = Scheme::timings[key];
        Scheme::timings[key] = ((value + temp)/2);

    }
}

int Scheme::getTiming(string key){

    return Scheme::timings[key];
}

void Scheme::startTimer(){

    Scheme::tempTime = clock();
}

long int Scheme::stopTimer(){

    time_t currentTime = clock();

    long int duration = static_cast<long int> (currentTime - Scheme::tempTime);
    return duration;
}

bool Scheme::randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    return gen();
}
