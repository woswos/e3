#include "gate-api.h"

#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>

void* GateApi::gate_and(void *bitA, void *bitB, void *key){

    // Cast back to data type from void
    TFheGateBootstrappingSecretKeySet  *keyset = static_cast<TFheGateBootstrappingSecretKeySet*>(Scheme::getKeySet());

    // Cast back to data type from void
    TFheGateBootstrappingParameterSet  *params = static_cast<TFheGateBootstrappingParameterSet*>(Scheme::getParameters());

    LweSample  *bitAPtr = static_cast<LweSample*>(bitA);
    LweSample  *bitBPtr = static_cast<LweSample*>(bitB);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    LweSample* result = new_gate_bootstrapping_ciphertext(params);

    /** bootstrapped And Gate: result = a and b */
    bootsAND(result, bitAPtr, bitBPtr, &keyset->cloud);

    // Cast to void from data type
    void  *voidResultPtr = static_cast<void*>(result);

    return voidResultPtr;
}
