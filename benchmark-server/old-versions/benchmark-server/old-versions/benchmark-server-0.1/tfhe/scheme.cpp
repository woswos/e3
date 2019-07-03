#include "tfhe.h"
#include "polynomials.h"
#include "lwesamples.h"
#include "lwekey.h"
#include "lweparams.h"
#include "tlwe.h"
#include "tgsw.h"

#include <stdio.h>
#include "Benchy.h"


using namespace std;

extern const TLweKey *debug_accum_key;
extern const LweKey *debug_extract_key;
extern const LweKey *debug_in_key;

int32_t main(int32_t argc, char **argv) {

    // Initialize a Benchy object for benchmarking the scheme
    Benchy scheme;

    // generate default gate bootstrapping parameters
    int32_t minimum_lambda = 100;
    const TFheGateBootstrappingParameterSet *params = new_default_gate_bootstrapping_parameters(minimum_lambda);

    // generate a random gate bootstrapping secret key
    const TFheGateBootstrappingSecretKeySet *keyset = new_random_gate_bootstrapping_secret_keyset(params);

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    const LweSample *cipher_text_a_1 = new_gate_bootstrapping_ciphertext(params);
    const LweSample *cipher_text_b_1 = new_gate_bootstrapping_ciphertext(params);
    LweSample *cipher_text_result_1 = new_gate_bootstrapping_ciphertext(params);


    // generate a new unititialized ciphertext (or an array of ciphertexts)
    const LweSample *cipher_text_a_2 = new_gate_bootstrapping_ciphertext(params);
    const LweSample *cipher_text_b_2 = new_gate_bootstrapping_ciphertext(params);
    LweSample *cipher_text_result_2 = new_gate_bootstrapping_ciphertext(params);

    scheme.startTimer("gate.nand_1");
    bootsNAND(cipher_text_result_1, cipher_text_a_1, cipher_text_b_1, &keyset->cloud);
    scheme.stopTimer();


    scheme.startTimer("gate.nand_1_1");
    bootsNAND(cipher_text_result_1, cipher_text_result_1, cipher_text_b_1, &keyset->cloud);
    scheme.stopTimer();

    // generate a new unititialized ciphertext (or an array of ciphertexts)
    const LweSample *cipher_text_a_3 = new_gate_bootstrapping_ciphertext(params);
    const LweSample *cipher_text_b_3 = new_gate_bootstrapping_ciphertext(params);
    LweSample *cipher_text_result_3 = new_gate_bootstrapping_ciphertext(params);

    scheme.startTimer("gate.nand_2");
    bootsNAND(cipher_text_result_2, cipher_text_b_1, cipher_text_b_2, &keyset->cloud);
    scheme.stopTimer();



    scheme.startTimer("gate.nand_3");
    bootsNAND(cipher_text_result_3, cipher_text_result_2, cipher_text_b_3, &keyset->cloud);
    scheme.stopTimer();

    scheme.finalizeBenchmark();

    return 0;
}
