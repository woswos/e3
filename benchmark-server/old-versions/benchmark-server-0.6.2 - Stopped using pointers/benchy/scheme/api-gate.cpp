/**********************************************************************************
benchy api for schemes that support gate operations

IMPORTANT NOTE: Please instantiate all objects in the heap memory, not stack memory
                For example use     Object* o = new Object();
                Don't use   Object* o;
                Please don't cout anything!
**********************************************************************************/

#include <map>
#include <memory>
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
    TFheGateBootstrappingParameterSet* params = new_default_gate_bootstrapping_parameters(minimum_lambda);

    // generate a new unititialized ciphertext
    LweSample* uCipherText = new_gate_bootstrapping_ciphertext(params);

    Scheme::StoreParameter("params", params);
    Scheme::StoreParameter("uCipherText", uCipherText);

}

// This function is called whenever new keys are required. You don't need to
//      return anything but store the pointers to your key parameters by using
//      Scheme::StoreParameter(string key, typename pointer) function.
// This function accepts any type of pointers and internally casts to void pointer type.
// Later, you will be able to call the stored pointer by using
//      Scheme::GetParameter<int>(string key) function. So, give it a meaningful key name.
// You can store as many pointers you want.
void Scheme::GenerateKeySet(){

    // cast back to data type from void
    TFheGateBootstrappingParameterSet* params = Scheme::GetParameter<TFheGateBootstrappingParameterSet*>("params");

    Scheme::StoreParameter("keyset", new_random_gate_bootstrapping_secret_keyset(params));

}

// This function will be called for encrypting plaintext values. Please return a
//      void type pointer to the cipher text. You achieve this by casting your
//      existing pointer to the cipher text.
// You can get required keys and parameters by calling Scheme::GetParameter<int>(string key)
//      function as mentioned previously. This function will return a void type pointer
//      and please cast this pointer to your reqired data type before utilizing.
void* Scheme::Encrypt(int plainText){

    // cast back to data type from void
    TFheGateBootstrappingParameterSet* params = Scheme::GetParameter<TFheGateBootstrappingParameterSet*>("params");

    // generate a new unititialized ciphertext

    //std::shared_ptr<LweSample*> encryptionResult = std::make_shared<LweSample*>(new_gate_bootstrapping_ciphertext(params));

    LweSample* encryptionResult = new_gate_bootstrapping_ciphertext(params);
    Scheme::StoreParameter("result", encryptionResult, true);

    // encrypts a boolean
    bootsSymEncrypt(encryptionResult, plainText, Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset"));

    return static_cast<void*>(encryptionResult);

}


int Scheme::Decrypt(void* cipherText){

    // Cast back to data type from void
    LweSample  *cipherTextPtr = static_cast<LweSample*>(cipherText);

    /** decrypts a boolean */
    return bootsSymDecrypt(cipherTextPtr, Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset"));
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

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* bitBPtr = static_cast<LweSample*>(bitB);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsAND(resultPtr, bitAPtr, bitBPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}


// Nand gate
void* GateApi::EvalNand(void *bitA, void *bitB){

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* bitBPtr = static_cast<LweSample*>(bitB);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsNAND(resultPtr, bitAPtr, bitBPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}

// Or gate
void* GateApi::EvalOr(void *bitA, void *bitB){

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* bitBPtr = static_cast<LweSample*>(bitB);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsOR(resultPtr, bitAPtr, bitBPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}

// Nor gate
void* GateApi::EvalNor(void *bitA, void *bitB){

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* bitBPtr = static_cast<LweSample*>(bitB);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsNOR(resultPtr, bitAPtr, bitBPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}

// Xor gate
void* GateApi::EvalXor(void *bitA, void *bitB){

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* bitBPtr = static_cast<LweSample*>(bitB);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsXOR(resultPtr, bitAPtr, bitBPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}

// Xnor gate
void* GateApi::EvalXnor(void *bitA, void *bitB){

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* bitBPtr = static_cast<LweSample*>(bitB);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsXNOR(resultPtr, bitAPtr, bitBPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}

// MUX gate
void* GateApi::EvalMux(void *bitA, void *bitB, void *bitC){

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* bitBPtr = static_cast<LweSample*>(bitB);
    LweSample* bitCPtr = static_cast<LweSample*>(bitC);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsMUX(resultPtr, bitAPtr, bitBPtr, bitCPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}

// Not gate
void* GateApi::EvalNot(void *bitA){

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsNOT(resultPtr, bitAPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}

// Buffer gate
void* GateApi::EvalBuffer(void *bitA){

    LweSample* bitAPtr = static_cast<LweSample*>(bitA);
    LweSample* resultPtr = Scheme::GetParameter<LweSample*>("uCipherText");

    bootsCOPY(resultPtr, bitAPtr, &Scheme::GetParameter<TFheGateBootstrappingSecretKeySet*>("keyset")->cloud);

    return static_cast<void*>(resultPtr);
}


/*************************************************/
/** Please don't modify the following functions **/
/*************************************************/
template <typename T>
void Scheme::StoreParameter(string key, T* pointer, bool track){

    void *ptr = static_cast<void*>(pointer);
    Scheme::parameters.insert({key, ptr});

}

template <typename T>
auto Scheme::GetParameter(string key) -> T{

    return static_cast<T>(Scheme::parameters[key]);
}

void Scheme::DeleteParameters(){

    // remove_before_flight
    for (auto it = Scheme::parameters.begin(); it != Scheme::parameters.end(); ++it){
        delete (char*)(*it).second;
    }

    Scheme::parameters.clear();

}

void Scheme::ClearTracked(){


}
