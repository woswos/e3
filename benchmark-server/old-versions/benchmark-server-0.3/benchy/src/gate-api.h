#ifndef GATE_API_H
#define GATE_API_H

#include "scheme-base.h"

class GateApi : public Scheme
{
private:
    void *resultPtr = 0;

public:

    void* gate_and(int bitA, int bitB);
    void* gate_nand(int bitA, int bitB);

    void* gate_or(int bitA, int bitB);
    void* gate_nor(int bitA, int bitBt);

    void* gate_xor(int bitA, int bitB);
    void* gate_xnor(int bitA, int bitB);

    void* gate_not(int bitA, int bitB);
    void* gate_buffer(int bitA, int bitB);
    void* gate_mux(int bitA, int bitB);

};

#endif
