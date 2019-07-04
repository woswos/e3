#ifndef API_BASE_H
#define API_BASE_H

#include <map>
#include <string>
#include <time.h>
#include <iostream>
#include <chrono>

using std::string;
using std::map;


class Scheme
{
private:
    struct CiphertextBit {};

    /********************************/
    /* Base Class Storage Variables */
    /********************************/
    // Holds the time durations for various operations tested
    // key, time value
    map<string, long long> timings;

    // Temporary time storage
    std::chrono::_V2::system_clock::time_point tempTime;


public:
    /**************/
    /* Scheme Api */
    /**************/
    // Identifies the homomorphic scheme in use
    std::string scheme_id;

    // Scheme dependent and scheme independent parameter setup
    void init();

    // Generate private key, public key, evaluation keys, etc.
    void generateKeySet();

    int test_gate(
                std::string gate_name_s,
                CiphertextBit (Scheme::*gate_func_name)(CiphertextBit, CiphertextBit)
                );

    // Encrypt a given plainText using the scheme
    //void* Encrypt(int plainText);

    // Decrypt a given plainText using the scheme
    //int Decrypt(void* cipherText);


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

    // For logging normal messages in a fancy way
    void consoleLog(string message);

    void consoleLogln(string message);

    // For logging error messages in a fancy way
    void consoleErrorLog(string message);

    /**********************/
    /* Benchmarking Stuff */
    /**********************/
    void addTiming(string key, long long value);
    long long getTiming(string key);

    // Assigns current clock() value to tempTime
    void startTimer();

    // Returns time difference based on the temporary time value when called
    long long stopTimer();

    // Return a random boolean value
    bool randomBool();

    // If there are things that need to be run both on gate and arithmetic apis,
    //      put them inside this function
    void base_benchmark();

    // Returns true of false if given values are equal to each other
    bool compare(int valueA, int valueB);

};

#endif
