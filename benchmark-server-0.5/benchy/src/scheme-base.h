#ifndef API_BASE_H
#define API_BASE_H

class Scheme
{
private:


public:
    void *parametersPtr = 0;
    void *keySetPtr = 0;
    void *aliceKeyPtr = 0;
    void *bobKeyPtr = 0;

    void *cipherTextPtr = 0;
    int message = 0;


    // Constructor
    //Scheme();

    // Destructor
    //~Scheme();

    // Copy constructor
    //Scheme(const Scheme &S);

    // Assignment
    //Scheme & operator=(const Scheme &S);

    // Parameter setup
    void* init();

    void* generateKeySet(void *setupPtr = 0);
    void* generateBobKey(void *setupPtr = 0);
    void* generateAliceKey(void *setupPtr = 0);

    void* encrypt(int message);
    int decrypt(void* cipherText);

    void* getBobKey(); // returns bobKeyPtr
    void* getAliceKey(); // returns aliceKeyPtr
    void* getKeySet(); // returns keySetPtr
    void* getParameters(); // returns parametersPtr

    // For deleting created objects
    void cleanup();

};

#endif
