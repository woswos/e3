#include "seal/seal.h"
#include "Benchy.h"

using namespace std;
using namespace seal;

int main() {

    // Initialize a Benchy object for benchmarking the scheme
    Benchy scheme;

    // Choose a scheme and create encytion parameters
    EncryptionParameters parms(scheme_type::BFV);
    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    parms.set_plain_modulus(256);
    auto context = SEALContext::Create(parms);


    // ~~~~~~ A naive way to calculate 2(x^2+1)(x+1)^2. ~~~~~~
    KeyGenerator keygen(context);
    PublicKey public_key = keygen.public_key();
    SecretKey secret_key = keygen.secret_key();

    Encryptor encryptor(context, public_key);
    Evaluator evaluator(context);
    Decryptor decryptor(context, secret_key);


    int x = 6;
    Plaintext x_plain(to_string(x));

    Ciphertext x_encrypted;
    scheme.startTimer("evaluation.encryption");
    encryptor.encrypt(x_plain, x_encrypted);
    scheme.stopTimer();

    Plaintext x_decrypted;
    scheme.startTimer("evaluation.decryption");
    decryptor.decrypt(x_encrypted, x_decrypted);
    scheme.stopTimer();

    // Compute x_sq_plus_one (x^2+1)
    Ciphertext x_sq_plus_one;

    scheme.startTimer("arithmetic.square");
    evaluator.square(x_encrypted, x_sq_plus_one);
    scheme.stopTimer();


    Plaintext plain_one("1");
    scheme.startTimer("arithmetic.addition");
    evaluator.add_plain_inplace(x_sq_plus_one, plain_one);
    scheme.stopTimer();


    // Compute (2(x^2+1))
    Plaintext plain_two("2");
    scheme.startTimer("arithmetic.multiplication");
    evaluator.multiply_plain_inplace(x_sq_plus_one, plain_two);
    scheme.stopTimer();

    scheme.finalizeBenchmark();
/*
    int x = 6;
    Plaintext x_plain(to_string(x));

    Ciphertext x_encrypted;
    encryptor.encrypt(x_plain, x_encrypted);

    Plaintext x_decrypted;
    decryptor.decrypt(x_encrypted, x_decrypted);


    // Compute x_sq_plus_one (x^2+1)
    Ciphertext x_sq_plus_one;
    evaluator.square(x_encrypted, x_sq_plus_one);
    Plaintext plain_one("1");
    evaluator.add_plain_inplace(x_sq_plus_one, plain_one);

    // If we want to decrypt to check the result
    Plaintext decrypted_result;
    decryptor.decrypt(x_sq_plus_one, decrypted_result);


    // Compute x_plus_one_sq ((x+1)^2)
    Ciphertext x_plus_one_sq;
    evaluator.add_plain(x_encrypted, plain_one, x_plus_one_sq);
    evaluator.square_inplace(x_plus_one_sq);


    // Compute encrypted_result (2(x^2+1)(x+1)^2)
    Ciphertext encrypted_result;
    Plaintext plain_two("2");
    evaluator.multiply_plain_inplace(x_sq_plus_one, plain_two);
    evaluator.multiply(x_sq_plus_one, x_plus_one_sq, encrypted_result);
*/

    return 0;
}
