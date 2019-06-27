/**********************************************************************************
benchy api for schemes that support arithmetic operations

IMPORTANT NOTE: Please instantiate all objects in the heap memory, not stack memory
                For example use     Object* o = new Object();
                Don't use   Object* o;
                Please don't cout anything!
**********************************************************************************/

#include "scheme-base.h"
#include "arithmetic.h"

/*************************************/
/** Please include your scheme here **/
/*************************************/
#include "seal/seal.h"

using namespace std;
using namespace seal;

/***********************/
/** GENERIC FUNCTIONS **/
/***********************/

// This function is called once in the beginning of the benchmark.
//      You can use this function to initilize required parameters
//      or pointers, etc.
void Scheme::init(){

    // Choose a scheme and create encytion parameters
    EncryptionParameters parms(scheme_type::BFV);
    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    parms.set_plain_modulus(256);

    //auto context = SEALContext::Create(parms);
    //std::shared_ptr<seal::SEALContext> context = SEALContext::Create(parms);

    std::shared_ptr<seal::SEALContext> *contextPtr = new std::shared_ptr<seal::SEALContext>(SEALContext::Create(parms));
    Scheme::storeParameter("context", contextPtr);

}

// This function is called whenever new keys are required. You don't need to
//      return anything but store the pointers to your key parameters by using
//      Scheme::storeParameter(string key, typename pointer) function.
// This function accepts any type of pointers and internally casts to void pointer type.
// Later, you will be able to call the stored pointer by using
//      Scheme::getParameter(string key) function. So, give it a meaningful key name.
// You can store as many pointers you want.
void Scheme::generateKeySet(){

    // cast back to data type from void
    std::shared_ptr<seal::SEALContext> *context = static_cast<std::shared_ptr<seal::SEALContext>*>(Scheme::getParameter("context"));

    KeyGenerator keygen(*context);
    PublicKey *public_keyPtr = new PublicKey(keygen.public_key());
    SecretKey *secret_keyPtr = new SecretKey(keygen.secret_key());

    Scheme::storeParameter("public_key", public_keyPtr);
    Scheme::storeParameter("secret_key", secret_keyPtr);

    Encryptor *encryptorPtr = new Encryptor(*context, *public_keyPtr);
    Evaluator *evaluatorPtr = new Evaluator(*context);
    Decryptor *decryptorPtr = new Decryptor(*context, *secret_keyPtr);

    Scheme::storeParameter("encryptor", encryptorPtr);
    Scheme::storeParameter("evaluator", evaluatorPtr);
    Scheme::storeParameter("decryptor", decryptorPtr);
}

// This function will be called for encrypting plaintext values. Please return a
//      void type pointer to the cipher text. You achieve this by casting your
//      existing pointer to the cipher text.
// You can get required keys and parameters by calling Scheme::getParameter(string key)
//      function as mentioned previously. This function will return a void type pointer
//      and please cast this pointer to your reqired data type before utilizing.
void* Scheme::encrypt(int message){

    // cast back to data type from void
    Encryptor *encryptor = static_cast<Encryptor*>(Scheme::getParameter("encryptor"));

    Plaintext x_plain(to_string(message));

    Ciphertext *x_encrypted_Ptr = new Ciphertext();

    encryptor->encrypt(x_plain, *x_encrypted_Ptr);

    return static_cast<void*>(x_encrypted_Ptr);

}


int Scheme::decrypt(void* cipherText){

    Decryptor  *decryptor = static_cast<Decryptor*>(Scheme::getParameter("decryptor"));

    // Cast back to data type from void
    Ciphertext  *cipherTextPtr = static_cast<Ciphertext*>(cipherText);

    Plaintext *x_decrypted_Ptr = new Plaintext();

    decryptor->decrypt(*cipherTextPtr, *x_decrypted_Ptr);

    return std::stoi(x_decrypted_Ptr->to_string());
}

void Scheme::cleanup(){
// remove_before_flight
}

/**************************/
/** ARITHMETIC FUNCTIONS **/
/**************************/
void* ArithmeticApi::arithmetic_add(void *valA, void *valB){

    // cast back to data type from void
    Evaluator *evaluator = static_cast<Evaluator*>(Scheme::getParameter("evaluator"));

    Ciphertext  *valAPtr = static_cast<Ciphertext*>(valA);
    Ciphertext  *valBPtr = static_cast<Ciphertext*>(valB);

    evaluator->add_inplace(*valAPtr, *valBPtr);

    return static_cast<void*>(valAPtr);
}

void* ArithmeticApi::arithmetic_subtract(void *valA, void *valB){

    void *ptr = 0;

    return ptr;
}

void* ArithmeticApi::arithmetic_multiply(void *valA, void *valB){

    // cast back to data type from void
    Evaluator *evaluator = static_cast<Evaluator*>(Scheme::getParameter("evaluator"));

    Ciphertext  *valAPtr = static_cast<Ciphertext*>(valA);
    Ciphertext  *valBPtr = static_cast<Ciphertext*>(valB);

    evaluator->multiply_inplace(*valAPtr, *valBPtr);

    return static_cast<void*>(valAPtr);

}

void* ArithmeticApi::arithmetic_square(void *valA){

    // cast back to data type from void
    Evaluator *evaluator = static_cast<Evaluator*>(Scheme::getParameter("evaluator"));

    Ciphertext  *valAPtr = static_cast<Ciphertext*>(valA);

    evaluator->square_inplace(*valAPtr);

    return static_cast<void*>(valAPtr);

}



/*************************************************/
/** Please don't modify the following functions **/
/*************************************************/
template <typename T>
void Scheme::storeParameter(string key, T* pointer){

    void *ptr = static_cast<void*>(pointer);
    Scheme::parameters.insert({key, ptr});

}

void* Scheme::getParameter(string key){

    return Scheme::parameters[key];
}
