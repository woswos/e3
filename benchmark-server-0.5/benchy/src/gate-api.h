#ifndef GATE_API_H
#define GATE_API_H

#include "scheme-base.h"

class GateApi : public Scheme
{
private:
    void *resultPtr = 0;

public:

    void* gate_and(void *bitA, void *bitB, void *key);
    void* gate_nand(void *bitA, void *bitB, void *key);

    void* gate_or(void *bitA, void *bitB, void *key);
    void* gate_nor(void *bitA, void *bitB, void *key);

    void* gate_xor(void *bitA, void *bitB, void *key);
    void* gate_xnor(void *bitA, void *bitB, void *key);

    void* gate_not(void *bitA, void *bitB, void *key);
    void* gate_buffer(void *bitA, void *bitB, void *key);
    void* gate_mux(void *bitA, void *bitB, void *key);

};

#endif
