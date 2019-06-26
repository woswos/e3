#include "scheme-base.h"

#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>

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
