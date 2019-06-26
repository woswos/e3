#ifndef GATE_API_H
#define GATE_API_H

#include "scheme-base.h"

class GateApi : public Scheme
{
private:

public:

    // Constructor
    GateApi(){};

    // Destructor
    ~GateApi(){};

    // Does the benchmarking, returns 1 if completed succesfully
    int benchmark();

    void* gate_and(void *bitA, void *bitB);
    void* gate_nand(void *bitA, void *bitB);

    void* gate_or(void *bitA, void *bitB);
    void* gate_nor(void *bitA, void *bitB);

    void* gate_xor(void *bitA, void *bitB);
    void* gate_xnor(void *bitA, void *bitB);

    void* gate_mux(void *bitA, void *bitB, void *bitC);
    void* gate_not(void *bitA);
    void* gate_buffer(void *bitA);

};

#endif
