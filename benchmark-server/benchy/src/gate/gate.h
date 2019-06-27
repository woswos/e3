#ifndef GATE_API_H
#define GATE_API_H

#include "scheme-base.h"

class GateApi : public Scheme
{
private:

public:
    /*******************/
    /* Gate Api Basics */
    /*******************/
    // Constructor
    GateApi(){};

    // Destructor
    ~GateApi(){};

    /*******************/
    /* Supported Gates */
    /*******************/
    void* gate_and(void *bitA, void *bitB);
    void* gate_nand(void *bitA, void *bitB);

    void* gate_or(void *bitA, void *bitB);
    void* gate_nor(void *bitA, void *bitB);

    void* gate_xor(void *bitA, void *bitB);
    void* gate_xnor(void *bitA, void *bitB);

    void* gate_mux(void *bitA, void *bitB, void *bitC);
    void* gate_not(void *bitA);
    void* gate_buffer(void *bitA);

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
