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
    // key, void pointer
    map<string, void *> parameters;

    // key, time value
    map<string, long int> timings;

    time_t tempTime;

public:

    // Constructor
    //Scheme();

    // Destructor
    //~Scheme();

    // Copy constructor
    //Scheme(const Scheme &S);

    // Assignment
    //Scheme & operator=(const Scheme &S);

    void base_benchmark();

    void addTiming(string key, long int value);
    int getTiming(string key);

    void startTimer();
    // returns time difference based on the temporary time value when called
    long int stopTimer();

    bool randomBool();


    // Parameter setup
    void init();

    void generateKeySet();

    void* encrypt(int message);
    int decrypt(void* cipherText);

    // returns void pointers based on given key
    void* getParameter(string key);

    // stores void pointers based on given key
    // casts given pointers to void
    template <typename T>
    void storeParameter(string key, T* pointer);

    // For deleting created objects
    void cleanup();

};

#endif
