#ifndef ARITHMETIC_API_H
#define ARITHMETIC_API_H

#include "scheme-base.h"

class ArithmeticApi : public Scheme
{
private:

public:
    /***********************************/
    /* Supported Arithmetic Operations */
    /***********************************/
    // ValA and ValB are ciphertexts
    void* EvalAdd(void *valA, void *valB);
    void* EvalMult(void *valA, void *valB);
    void* EvalSub(void *valA, void *valB);

    void* EvalNegate(void *valA);
    void* EvalSquare(void *valA);
    void* EvalCube(void *valA);

    void* EvalPermuteRow(void *valA);
    void* EvalPermuteCol(void *valA);

    void* EvalDotProduct(void *valA, void *valB);
    void* EvalLinearTransformation(void *valA, void *valB);
    void* EvalDFT(void *valA, void *valB);

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

};

#endif
