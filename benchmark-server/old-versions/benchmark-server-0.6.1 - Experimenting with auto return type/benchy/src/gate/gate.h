#ifndef GATE_API_H
#define GATE_API_H

#include "base.h"

class GateApi : public Scheme
{
private:

public:
    /*******************/
    /* Supported Gates */
    /*******************/
    void Init(){

        // generate default gate bootstrapping parameters
        int32_t minimum_lambda = 100;
        TFheGateBootstrappingParameterSet* params = new_default_gate_bootstrapping_parameters(minimum_lambda);

        // generate a new unititialized ciphertext
        LweSample* uCipherText = new_gate_bootstrapping_ciphertext(params);

        Scheme::StoreParameter("params", params);
        Scheme::StoreParameter("uCipherText", uCipherText);

    }

    void GenerateKeySet(){

        // cast back to data type from void
        TFheGateBootstrappingParameterSet* params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

        TFheGateBootstrappingSecretKeySet* keyset = new_random_gate_bootstrapping_secret_keyset(params);

        Scheme::StoreParameter("keyset", keyset);

    }

    auto Encrypt(int plainText) -> LweSample* {

        // cast back to data type from void
        TFheGateBootstrappingSecretKeySet* keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
        TFheGateBootstrappingParameterSet* params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

        // generate a new unititialized ciphertext
        LweSample* encryptionResult = new_gate_bootstrapping_ciphertext(params);
        Scheme::StoreParameter("encryptionResult", encryptionResult);

        // encrypts a boolean
        bootsSymEncrypt(encryptionResult, plainText, keyset);

        return encryptionResult;

    }

    template <typename T>
    int Decrypt(T cipherText){

        TFheGateBootstrappingSecretKeySet* keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));

        /** decrypts a boolean */
        return bootsSymDecrypt(cipherText, keyset);
    }


    template <typename T>
    auto EvalAnd(T bitA, T bitB)  -> LweSample*{

        // cast back to data type from void
        TFheGateBootstrappingSecretKeySet* keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::GetParameter("keyset"));
        TFheGateBootstrappingParameterSet* params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::GetParameter("params"));

        LweSample* resultPtr = static_cast<LweSample*>(Scheme::GetParameter("uCipherText"));

        /** bootstrapped And Gate: result = a and b */
        bootsAND(resultPtr, bitA, bitB, &keyset->cloud);

        return resultPtr;
    }


    void* EvalNand(void *bitA, void *bitB);

    void* EvalOr(void *bitA, void *bitB);
    void* EvalNor(void *bitA, void *bitB);

    void* EvalXor(void *bitA, void *bitB);
    void* EvalXnor(void *bitA, void *bitB);

    void* EvalMux(void *bitA, void *bitB, void *bitC);
    void* EvalNot(void *bitA);
    void* EvalBuffer(void *bitA);


    /*******************/
    /* Gate Api Basics */
    /*******************/
    // Constructor
    GateApi(){};

    // Destructor
    ~GateApi(){};

    /**********************/
    /* Benchmarking Stuff */
    /**********************/
    // Does the benchmarking, returns 1 if completed succesfully
    int benchmark(GateApi* schemePtr);

    int test_gate_cycle_recursive_ciphertext(
                        std::string gate_name_s,
                        GateApi* schemePtr,
                        void* (GateApi::*gate_func_name)(void*, void*),
                        int (GateApi::*test_gate_func_name)(int, int)
                        );

    int test_gate_cycle_fresh_ciphertext(
                        std::string gate_name_s,
                        GateApi* schemePtr,
                        void* (GateApi::*gate_func_name)(void*, void*),
                        int (GateApi::*test_gate_func_name)(int, int)
                        );

    int test_gate_manual_single(int bitA, int bitB);

    int test_gate_and(int bitA, int bitB);
    int test_gate_nand(int bitA, int bitB);

    int test_gate_or(int bitA, int bitB);
    int test_gate_nor(int bitA, int bitB);

    int test_gate_xor(int bitA, int bitB);
    int test_gate_xnor(int bitA, int bitB);

    int test_gate_mux(int bitA, int bitB, int bitC);
    int test_gate_not(int bitA);
    int test_gate_buffer(int bitA);

};

#endif
