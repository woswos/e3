#include "gate-api.h"
#include <iostream>

#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>

int GateApi::benchmark(){

    GateApi::base_benchmark();

    void *result = 0;

    for (size_t i = 0; i < 100; i++) {

        void *bitA = GateApi::encrypt(GateApi::randomBool());
        void *bitB = GateApi::encrypt(GateApi::randomBool());

        GateApi::startTimer();
        result = GateApi::gate_and(bitA, bitB);
        GateApi::addTiming("gate_and", GateApi::stopTimer());
    }


    GateApi::startTimer();
    GateApi::decrypt(result);
    GateApi::addTiming("decrypt", GateApi::stopTimer());

    GateApi::cleanup();


    std::cout << GateApi::getTiming("gate_and") << " microsecs \n";
    std::cout << GateApi::getTiming("decrypt") << " microsecs \n";

    return 1;
}

void* GateApi::gate_and(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsAND(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

void* GateApi::gate_nand(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsNAND(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

void* GateApi::gate_or(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsOR(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

void* GateApi::gate_nor(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsNOR(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

void* GateApi::gate_xor(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsXOR(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

void* GateApi::gate_xnor(void *bitA, void *bitB){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsXNOR(result, bitAPtr, bitBPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

void* GateApi::gate_mux(void *bitA, void *bitB, void *bitC){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);
    LweSample  *bitCPtr = static_cast<LweSample*>(bitC);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsMUX(result, bitAPtr, bitBPtr, bitCPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

void* GateApi::gate_not(void *bitA){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsNOT(result, bitAPtr, &keyset->cloud);

    return static_cast<void*>(result);
}

void* GateApi::gate_buffer(void *bitA){

    // cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getParameter("keyset"));
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameter("params"));

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsCOPY(result, bitAPtr, &keyset->cloud);

    return static_cast<void*>(result);
}
