#include <stdio.h>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sys/time.h>
#include "tfhe.h"
#include "polynomials.h"
#include "lwesamples.h"
#include "lwekey.h"
#include "lweparams.h"
#include "tlwe.h"
#include "tgsw.h"

using namespace std;
using namespace std::chrono; 

extern const TLweKey *debug_accum_key;
extern const LweKey *debug_extract_key;
extern const LweKey *debug_in_key;

// /** bootstrapped Nand Gate */ 
// void bootsNAND(LweSample* result, const LweSample* ca, const LweSample* cb, const TFheGateBootstrappingCloudKeySet* bk);

int32_t main(int32_t argc, char **argv) {

    const int32_t nb_samples = 64;
    const int32_t nb_trials = 1;

    /** generate default gate bootstrapping parameters */
    int32_t minimum_lambda = 100;
    const TFheGateBootstrappingParameterSet *params = new_default_gate_bootstrapping_parameters(minimum_lambda);


    /** generate a random gate bootstrapping secret key */
    const TFheGateBootstrappingSecretKeySet *keyset = new_random_gate_bootstrapping_secret_keyset(params);

    /** generate a new unititialized ciphertext (or an array of ciphertexts) */
    const LweSample *cipher_text_a = new_gate_bootstrapping_ciphertext(params);
    const LweSample *cipher_text_b = new_gate_bootstrapping_ciphertext(params);
    LweSample *cipher_text_result = new_gate_bootstrapping_ciphertext(params);


    /** bootstrapped Nand Gate */ 
    cout << "starting bootstrapping NAND" << endl;
	
    auto start = high_resolution_clock::now(); 
    bootsNAND(cipher_text_result, cipher_text_a, cipher_text_a, &keyset->cloud);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "finished bootstrappings NAND" << endl;
    cout << "time per bootNAND gate (microsecs)... " << duration.count() << endl;


/*
    const int32_t nb_samples = 64;
    const int32_t nb_trials = 1;

    // generate params 
    int32_t minimum_lambda = 100;
    TFheGateBootstrappingParameterSet *params = new_default_gate_bootstrapping_parameters(minimum_lambda);

    // generate the secret keyset
    TFheGateBootstrappingSecretKeySet *keyset = new_random_gate_bootstrapping_secret_keyset(params);

    // generate samples
    const LweSample *cipher_text_a = new_gate_bootstrapping_ciphertext(params);
    const LweSample *cipher_text_b = new_gate_bootstrapping_ciphertext(params);
    LweSample *cipher_text_result = new_gate_bootstrapping_ciphertext(params);

    bootsNAND(cipher_text_result, cipher_text_a, cipher_text_b, &keyset->cloud);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const int32_t nb_samples = 64;
    const int32_t nb_trials = 1;

    // generate params 
    int32_t minimum_lambda = 100;
    TFheGateBootstrappingParameterSet *params = new_default_gate_bootstrapping_parameters(minimum_lambda);
    const LweParams *in_out_params = params->in_out_params;

    // generate the secret keyset
    TFheGateBootstrappingSecretKeySet *keyset = new_random_gate_bootstrapping_secret_keyset(params);


    for (int32_t trial = 0; trial < nb_trials; ++trial) {

        // generate samples
        LweSample *test_in = new_LweSample_array(2 * nb_samples, in_out_params);

        // generate inputs (64-->127)
        for (int32_t i = nb_samples; i < 2 * nb_samples; ++i) {
            bootsSymEncrypt(test_in + i, rand() % 2, keyset);
        }

        // fake encrypt
        bootsSymEncrypt(test_in + 0, rand() % 2, keyset);

        // evaluate the NAND tree
        cout << "starting bootstrapping NAND tree...trial " << trial << endl;
        clock_t begin = clock();
        for (int32_t i = nb_samples - 1; i > 0; --i) {
            bootsNAND(test_in + i, test_in + (2 * i), test_in + (2 * i + 1), &keyset->cloud);
        }
        clock_t end = clock();
        cout << "finished bootstrappings NAND tree" << endl;
        cout << "time per bootNAND gate (microsecs)... " << (end - begin) / double(nb_samples - 1) << endl;

        // verification
        for (int32_t i = nb_samples - 1; i > 0; --i) {
            bool mess1 = bootsSymDecrypt(test_in + (2 * i), keyset);
            bool mess2 = bootsSymDecrypt(test_in + (2 * i + 1), keyset);
            bool out = bootsSymDecrypt(test_in + i, keyset);

            if (out != 1 - (mess1 * mess2)) {
                cout << "ERROR!!! " << trial << "," << i << " - ";
                cout << t32tod(lwePhase(test_in + i, keyset->lwe_key)) << " - ";
                cout << t32tod(lwePhase(test_in + (2 * i), keyset->lwe_key)) << " - ";
                cout << t32tod(lwePhase(test_in + (2 * i + 1), keyset->lwe_key)) << endl;
            }

        }

        delete_LweSample_array(2 * nb_samples, test_in);
    }

    delete_gate_bootstrapping_secret_keyset(keyset);
    delete_gate_bootstrapping_parameters(params);
*/
    return 0;
}
