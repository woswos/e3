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


    /**************/
    /* Scheme Api */
    /**************/
    // Parameter setup
    void init();

    // Generate private key, public key, evaluation keys, etc.
    void generateKeySet();

    // Encrypt a given message using the scheme
    void* encrypt(int message);

    // Decrypt a given message using the scheme
    int decrypt(void* cipherText);

    // Returns void pointers based on given key
    void* getParameter(string key);

    // Stores void pointers based on given key and casts given pointers to void
    template <typename T>
    void storeParameter(string key, T* pointer);

    // For deleting created objects
    void cleanup();

};

#endif
