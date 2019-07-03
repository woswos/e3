#ifndef API_BASE_H
#define API_BASE_H

class Scheme
{
public:
    template <typename T>
    struct initParams {
        T *setupPtr = 0;
    };

    template <typename T>
    struct keys {
        T *aliceKeyPtr = 0;
        T *bobKeyPtr = 0;
    };

    template <typename T>
    struct data {
        T *cipherTextPtr = 0;
        T *messagePtr = 0;
    };


public:
    // Constructor
    //Scheme();

    // Destructor
    //~Scheme();

    // Copy constructor
    //Scheme(const Scheme &S);

    // Assignment
    //Scheme & operator=(const Scheme &S);

    // Parameter setup
    void init();

    void generateBobKey();
    void generateAliceKey();

    void getBobKey(); // returns bobKeyPtr
    void getAliceKey(); // returns aliceKeyPtrx

    void encrypt();
    void decrypt();

    // For deleting created objects
    void cleanup();

};

#endif
