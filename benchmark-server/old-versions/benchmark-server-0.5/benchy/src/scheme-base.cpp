#include "scheme-base.h"
#include <iostream>

#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>

void* Scheme::init(){

    // generate default gate bootstrapping parameters
    int32_t minimum_lambda = 100;
    TFheGateBootstrappingParameterSet *params = new_default_gate_bootstrapping_parameters(minimum_lambda);

    // Cast to void from data type
    void  *paramsPtr = static_cast<void*>(params);

    return paramsPtr;
}

void* Scheme::generateKeySet(void *setupPtr){

    // Cast back to data type from void
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(setupPtr);


    TFheGateBootstrappingSecretKeySet *keyset = new_random_gate_bootstrapping_secret_keyset(params);


    // Cast to void from data type
    void  *voidKeysetPtr = static_cast<void*>(keyset);

    return voidKeysetPtr;
}


void* Scheme::encrypt(int message){

    // Cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getKeySet());

    // Cast back to data type from void
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameters());


    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** encrypts a boolean */
    bootsSymEncrypt(result, message, keyset);


    // Cast to void from data type
    void  *voidResultPtr = static_cast<void*>(result);

    return voidResultPtr;
}


int Scheme::decrypt(void* cipherText){

    // Cast back to data type from void
    LweSample  *cipherTextPtr = static_cast<LweSample*>(cipherText);

    // Cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getKeySet());

    /** decrypts a boolean */
    return bootsSymDecrypt(cipherTextPtr, keyset);
}


void Scheme::cleanup(){


}


void* Scheme::getKeySet(){
    return this->keySetPtr;
}

void* Scheme::getParameters(){
    return this->parametersPtr;
}
