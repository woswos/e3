#include "seal/seal.h"
#include "Benchy.h"


using namespace std;
using namespace seal;

int main() {

    // Initialize a Benchy object for benchmarking the scheme
    Benchy scheme;

    EncryptionParameters parms(scheme_type::BFV);

    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);

    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));

    parms.set_plain_modulus(256);

    auto context = SEALContext::Create(parms);

    cout << "Set encryption parameters" << endl;

    cout << endl;
    cout << "~~~~~~ A naive way to calculate 2(x^2+1)(x+1)^2. ~~~~~~" << endl;


    KeyGenerator keygen(context);
    PublicKey public_key = keygen.public_key();
    SecretKey secret_key = keygen.secret_key();

    Encryptor encryptor(context, public_key);

    Evaluator evaluator(context);

    Decryptor decryptor(context, secret_key);

    int x = 6;
    Plaintext x_plain(to_string(x));
    cout << "Express x = " + to_string(x) +
        " as a plaintext polynomial 0x" + x_plain.to_string() + "." << endl;


    Ciphertext x_encrypted;
    cout << "Encrypt x_plain to x_encrypted." << endl;
    encryptor.encrypt(x_plain, x_encrypted);

    cout << "    + size of freshly encrypted x: " << x_encrypted.size() << endl;

    cout << "    + noise budget in freshly encrypted x: "
        << decryptor.invariant_noise_budget(x_encrypted) << " bits" << endl;


    Plaintext x_decrypted;
    cout << "    + decryption of x_encrypted: ";
    decryptor.decrypt(x_encrypted, x_decrypted);
    cout << "0x" << x_decrypted.to_string() << " ...... Correct." << endl;


    cout << "Compute x_sq_plus_one (x^2+1)." << endl;
    Ciphertext x_sq_plus_one;
    evaluator.square(x_encrypted, x_sq_plus_one);
    Plaintext plain_one("1");
    evaluator.add_plain_inplace(x_sq_plus_one, plain_one);


    cout << "    + size of x_sq_plus_one: " << x_sq_plus_one.size() << endl;
    cout << "    + noise budget in x_sq_plus_one: "
        << decryptor.invariant_noise_budget(x_sq_plus_one) << " bits" << endl;


    Plaintext decrypted_result;
    cout << "    + decryption of x_sq_plus_one: ";
    decryptor.decrypt(x_sq_plus_one, decrypted_result);
    cout << "0x" << decrypted_result.to_string() << " ...... Correct." << endl;


    cout << "Compute x_plus_one_sq ((x+1)^2)." << endl;
    Ciphertext x_plus_one_sq;
    evaluator.add_plain(x_encrypted, plain_one, x_plus_one_sq);
    evaluator.square_inplace(x_plus_one_sq);
    cout << "    + size of x_plus_one_sq: " << x_plus_one_sq.size() << endl;
    cout << "    + noise budget in x_plus_one_sq: "
        << decryptor.invariant_noise_budget(x_plus_one_sq)
        << " bits" << endl;
    cout << "    + decryption of x_plus_one_sq: ";
    decryptor.decrypt(x_plus_one_sq, decrypted_result);
    cout << "0x" << decrypted_result.to_string() << " ...... Correct." << endl;


    cout << "Compute encrypted_result (2(x^2+1)(x+1)^2)." << endl;
    Ciphertext encrypted_result;
    Plaintext plain_two("2");
    evaluator.multiply_plain_inplace(x_sq_plus_one, plain_two);
    evaluator.multiply(x_sq_plus_one, x_plus_one_sq, encrypted_result);
    cout << "    + size of encrypted_result: " << encrypted_result.size() << endl;
    cout << "    + noise budget in encrypted_result: "
        << decryptor.invariant_noise_budget(encrypted_result) << " bits" << endl;
    cout << "NOTE: Decryption can be incorrect if noise budget is zero." << endl;

    cout << endl;
    cout << "~~~~~~ A better way to calculate 2(x^2+1)(x+1)^2. ~~~~~~" << endl;


    cout << "Generate relinearization keys." << endl;
    auto relin_keys = keygen.relin_keys();


    cout << "Compute and relinearize x_squared (x^2)," << endl;
    cout << string(13, ' ') << "then compute x_sq_plus_one (x^2+1)" << endl;
    Ciphertext x_squared;
    evaluator.square(x_encrypted, x_squared);
    cout << "    + size of x_squared: " << x_squared.size() << endl;
    evaluator.relinearize_inplace(x_squared, relin_keys);
    cout << "    + size of x_squared (after relinearization): "
        << x_squared.size() << endl;
    evaluator.add_plain(x_squared, plain_one, x_sq_plus_one);
    cout << "    + noise budget in x_sq_plus_one: "
        << decryptor.invariant_noise_budget(x_sq_plus_one) << " bits" << endl;
    cout << "    + decryption of x_sq_plus_one: ";
    decryptor.decrypt(x_sq_plus_one, decrypted_result);
    cout << "0x" << decrypted_result.to_string() << " ...... Correct." << endl;


    Ciphertext x_plus_one;
    cout << "Compute x_plus_one (x+1)," << endl;
    cout << string(13, ' ')
        << "then compute and relinearize x_plus_one_sq ((x+1)^2)." << endl;
    evaluator.add_plain(x_encrypted, plain_one, x_plus_one);
    evaluator.square(x_plus_one, x_plus_one_sq);
    cout << "    + size of x_plus_one_sq: " << x_plus_one_sq.size() << endl;
    evaluator.relinearize_inplace(x_plus_one_sq, relin_keys);
    cout << "    + noise budget in x_plus_one_sq: "
        << decryptor.invariant_noise_budget(x_plus_one_sq) << " bits" << endl;
    cout << "    + decryption of x_plus_one_sq: ";
    decryptor.decrypt(x_plus_one_sq, decrypted_result);
    cout << "0x" << decrypted_result.to_string() << " ...... Correct." << endl;


    cout << "Compute and relinearize encrypted_result (2(x^2+1)(x+1)^2)." << endl;
    evaluator.multiply_plain_inplace(x_sq_plus_one, plain_two);
    evaluator.multiply(x_sq_plus_one, x_plus_one_sq, encrypted_result);
    cout << "    + size of encrypted_result: " << encrypted_result.size() << endl;
    evaluator.relinearize_inplace(encrypted_result, relin_keys);
    cout << "    + size of encrypted_result (after relinearization): "
        << encrypted_result.size() << endl;
    cout << "    + noise budget in encrypted_result: "
        << decryptor.invariant_noise_budget(encrypted_result) << " bits" << endl;

    cout << endl;
    cout << "NOTE: Notice the increase in remaining noise budget." << endl;


    cout << "Decrypt encrypted_result (2(x^2+1)(x+1)^2)." << endl;
    decryptor.decrypt(encrypted_result, decrypted_result);
    cout << "    + decryption of 2(x^2+1)(x+1)^2 = 0x"
        << decrypted_result.to_string() << " ...... Correct." << endl;
    cout << endl;


    return 0;
}
