#ifndef API_BASE_H
#define API_BASE_H

#include <map>
#include <string>
#include <time.h>

using std::string;
using std::map;

class Scheme
{
private:
    /********************************/
    /* Base Class Storage Variables */
    /********************************/
    // Hold void pointers to various paramaters supplied by the scheme
    // key, void pointer
    map<string, void *> parameters;

    // Holds the time durations for various operations tested
    // key, time value
    map<string, long int> timings;

    // Temporary time storage
    time_t tempTime;


public:
    /**************/
    /* Scheme Api */
    /**************/
    // Identifies the homomorphic scheme in use
    std::string scheme_id;
    
    // Scheme dependent and scheme independent parameter setup
    void Init();

    // Generate private key, public key, evaluation keys, etc.
    void GenerateKeySet();

    // Encrypt a given plainText using the scheme
    void* Encrypt(int plainText);

    // Decrypt a given plainText using the scheme
    int Decrypt(void* cipherText);

    // Applies the relinearization operation to a given input ciphertext
    void* Relinearize(void* cipherText);

    // Resets the noise in a given input ciphertext to a specific level determined
    //      by the parameters
    void* Bootstrap(void* cipherText);

    // Change ciphertext coefficient modulus to smaller or larger value.
    void* ModSwitch(void* cipherText);

    // Re-randomize a given ciphertext
    void* ReRandomize(void* cipherText);

    // Switches an input ciphertext from using one secret key to another secret
    //      key without changing the underlying plaintext
    void* KeySwitch(void* cipherText);

    // Estimate the noise growth in the current circuit
    void NoiseEstimate();

    // Relinearize
    // Rescale
    // Rotate one
    // Rotate random
    // Conjugate
    // https://github.com/microsoft/SEAL/blob/0b0b5dd68e95c83d0c357d17af9b862df55cb8ea/dotnet/examples/6_Performance.cs#L337


    // Returns void pointers based on given key
    void* GetParameter(string key);

    // Stores void pointers based on given key and casts given pointers to void
    template <typename T>
    void StoreParameter(string key, T* pointer);

    // For deleting created objects
    void Cleanup();


    /*********************/
    /* Base Class Basics */
    /*********************/
    // Constructor
    Scheme(){};

    // Destructor
    ~Scheme(){};

    // Copy constructor
    Scheme(const Scheme &S);

    // Assignment
    Scheme & operator=(const Scheme &S);


    /**********************/
    /* Benchmarking Stuff */
    /**********************/
    void addTiming(string key, long int value);
    int getTiming(string key);

    // Assigns current clock() value to tempTime
    void startTimer();

    // Returns time difference based on the temporary time value when called
    long int stopTimer();

    // Return a random boolean value
    bool randomBool();

    // If there are things that need to be run both on gate and arithmetic apis,
    //      put them inside this function
    void base_benchmark();

    // Returns true of false if given values are equal to each other
    bool compare(int valueA, int valueB);

};

#endif
