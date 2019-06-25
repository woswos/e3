#ifndef API_BASE_H
#define API_BASE_H

class Scheme
{
private:


public:
    void *setupPtr = 0;
    void *aliceKeyPtr = 0;
    void *bobKeyPtr = 0;
    void *parametersPtr = 0;
    void *cipherTextPtr = 0;
    void *messagePtr = 0;


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

    void* generateBobKey(void *setupPtr = 0);
    void* generateAliceKey(void *setupPtr = 0);

    void* encrypt(void* message);
    void* decrypt(void* cipherText);

    void* getBobKey(); // returns bobKeyPtr
    void* getAliceKey(); // returns aliceKeyPtr

    // For deleting created objects
    void cleanup();

};

#endif
