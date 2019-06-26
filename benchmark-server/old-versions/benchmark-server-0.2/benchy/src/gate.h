#pragma once

#include "benchy.h"
#include "bit.h"
#include <iostream>

class Gate : public Benchy
{
public:
    //void benchmark();

    void gate_and(Bit& a, Bit& b, Bit& result);
    void gate_nand(Bit& a, Bit& b, Bit& result);

    void gate_or(Bit& a, Bit& b, Bit& result);
    void gate_nor(Bit& a, Bit& b, Bit& result);

    void gate_xor(Bit& a, Bit& b, Bit& result);
    void gate_xnor(Bit& a, Bit& b, Bit& result);

    void gate_not(Bit& a, Bit& result);
    void gate_buffer(Bit& a, Bit& result);
    void gate_mux(Bit& a, Bit& b, Bit& result);

};
