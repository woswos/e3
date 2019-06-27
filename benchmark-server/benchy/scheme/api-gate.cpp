/**********************************************************************************
benchy api for schemes that support gate operations

IMPORTANT NOTE: Please instantiate all objects in the heap memory, not stack memory
                For example use     Object* o = new Object();
                Don't use   Object* o;
                Please don't cout anything!
**********************************************************************************/

#include "base.h"
#include "gate.h"

/*************************************/
/** Please include your scheme here **/
/*************************************/
#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>

/***********************/
/** GENERIC FUNCTIONS **/
/***********************/

// This function is called once in the beginning of the benchmark.
//      You can use this function to initilize required parameters
//      or pointers, etc.
void Scheme::Init(){

    // generate default gate bootstrapping parameters
    int32_t minimum_lambda = 100;
    TFheGateBootstrappingParameterSet *params = new_default_gate_bootstrapping_parameters(minimum_lambda);

    Scheme::StoreParameter("params", params);

}

// This function is called whenever new keys are required. You don't need to
//      return anything but store the pointers to your key parameters by using
//      Scheme::StoreParameter(string key, typename pointer) function.
// This function accepts any type of pointers and internally casts to void pointer type.
// Later, you will be able to call the stored pointer by using
//      Scheme::GetParameter(string key) function. So, give it a meaningful key name.
// You can store as many pointers you want.
void Scheme::GenerateKeySet(){

    // cast back to data type from void
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    TFheGateBootstrappingSecretKeySet *keyset = new_random_gate_bootstrapping_secret_keyset(params);

    Scheme::StoreParameter("keyset", keyset);

}

// This function will be called for encrypting plaintext values. Please return a
//      void type pointer to the cipher text. You achieve this by casting your
//      existing pointer to the cipher text.
// You can get required keys and parameters by calling Scheme::GetParameter(string key)
//      function as mentioned previously. This function will return a void type pointer
//      and please cast this pointer to your reqired data type before utilizing.
void* Scheme::Encrypt(int plainText){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    // generate a new unititialized ciphertext
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    // encrypts a boolean
    bootsSymEncrypt(result, plainText, keyset);

    return static_cast<void*>(result);

}


int Scheme::Decrypt(void* cipherText){

    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));

    // Cast back to data type from void
    LweSample  *cipherTextPtr = static_cast<LweSample*>(cipherText);

    /** decrypts a boolean */
    return bootsSymDecrypt(cipherTextPtr, keyset);
}

void Scheme::Cleanup(){
// remove_before_flight
}

/********************/
/** GATE FUNCTIONS **/
/********************/
// For gates, you will be provided coid pointers to cipher texts that was encrypted
//      by using the encrypt() function you defined above. Please cast provided void
//      pointers to your cipher text data type before using.
// You should return a void pointer to the result after completing the gate operation

// And gate
void* GateApi::EvalAnd(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsAND(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

// Nand gate
void* GateApi::EvalNand(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsNAND(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

// Or gate
void* GateApi::EvalOr(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsOR(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

// Nor gate
void* GateApi::EvalNor(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsNOR(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

// Xor gate
void* GateApi::EvalXor(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsXOR(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

// Xnor gate
void* GateApi::EvalXnor(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsXNOR(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

// MUX gate
void* GateApi::EvalMux(void *bitA, void *bitB, void *bitC){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);
    LweSample  *bitCPtr = static_cast<LweSample*>(bitC);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsMUX(result, bitAPtr, bitBPtr, bitCPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

// Not gate
void* GateApi::EvalNot(void *bitA){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsNOT(result, bitAPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

// Buffer gate
void* GateApi::EvalBuffer(void *bitA){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsCOPY(result, bitAPtr, &keyset->cloud);

    return static_cast<void*>(result);
}


/*************************************************/
/** Please don't modify the following functions **/
/*************************************************/
template <typename T>
void Scheme::StoreParameter(string key, T* pointer){

    void *ptr = static_cast<void*>(pointer);
    Scheme::parameters.insert({key, ptr});

}

void* Scheme::GetParameter(string key){

    return Scheme::parameters[key];
}
