#ifndef GATE_API_H
#define GATE_API_H

#include "scheme-base.h"

class GateApi : public Scheme
{
private:

public:
    /*******************/
    /* Supported Gates */
    /*******************/
    void* EvalAnd(void *bitA, void *bitB);
    void* EvalNand(void *bitA, void *bitB);

    void* EvalOr(void *bitA, void *bitB);
    void* EvalNor(void *bitA, void *bitB);

    void* EvalXor(void *bitA, void *bitB);
    void* EvalXnor(void *bitA, void *bitB);

    void* EvalMux(void *bitA, void *bitB, void *bitC);
    void* EvalNot(void *bitA);
    void* EvalBuffer(void *bitA);


    /*******************/
    /* Gate Api Basics */
    /*******************/
    // Constructor
    GateApi(){};

    // Destructor
    ~GateApi(){};


    /**********************/
    /* Benchmarking Stuff */
    /**********************/
    // Does the benchmarking, returns 1 if completed succesfully
    int benchmark(GateApi* schemePtr);

    int test_gate_cycle_fresh_ciphertext(
                        std::string gate_name_s,
                        GateApi* schemePtr,
                        void* (GateApi::*gate_func_name)(void*, void*),
                        int (GateApi::*test_gate_func_name)(int, int)
                        );

    int test_gate_and(int bitA, int bitB);
    int test_gate_nand(int bitA, int bitB);

    int test_gate_or(int bitA, int bitB);
    int test_gate_nor(int bitA, int bitB);

    int test_gate_xor(int bitA, int bitB);
    int test_gate_xnor(int bitA, int bitB);

    int test_gate_mux(int bitA, int bitB, int bitC);
    int test_gate_not(int bitA);
    int test_gate_buffer(int bitA);

    int test(){
        return 0;
    };
};

#endif
