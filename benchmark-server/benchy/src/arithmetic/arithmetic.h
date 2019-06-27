#ifndef ARITHMETIC_API_H
#define ARITHMETIC_API_H

#include "scheme-base.h"

class ArithmeticApi : public Scheme
{
private:

public:
    /*************************/
    /* Arithmetic Api Basics */
    /*************************/
    // Constructor
    ArithmeticApi(){};

    // Destructor
    ~ArithmeticApi(){};

    /**********************/
    /* Benchmarking Stuff */
    /**********************/
    // Does the benchmarking, returns 1 if completed succesfully
    int benchmark(ArithmeticApi* schemePtr);

    /***********************************/
    /* Supported Arithmetic Operations */
    /***********************************/
    void* arithmetic_add(void *valA, void *valB);

    void* arithmetic_multiply(void *valA, void *valB);
    void* arithmetic_square(void *valA);

    //void* arithmetic_subtract(void *valA, void *valB);
    // Relinearize
    // Rescale
    // Rotate one
    // Rotate random
    // Conjugate
    // https://github.com/microsoft/SEAL/blob/0b0b5dd68e95c83d0c357d17af9b862df55cb8ea/dotnet/examples/6_Performance.cs#L337
};

#endif
