#include "gate.h"
#include <iostream>
#include <functional>
#include <string>

#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>

int GateApi::benchmark(GateApi* schemePtr){

    // Runs GateApi::init() and GateApi::generateKeySet()
    GateApi::base_benchmark();

    std::cout << GateApi::Decrypt(GateApi::EvalAnd(GateApi::Encrypt(1), GateApi::Encrypt(0))) << "\n";

    return 1;
}



int GateApi::test_gate_and(int bitA, int bitB){
    return (bitA && bitB);
}

int GateApi::test_gate_nand(int bitA, int bitB){
    return !(bitA && bitB);
}

int GateApi::test_gate_or(int bitA, int bitB){
    return (bitA || bitB);
}

int GateApi::test_gate_nor(int bitA, int bitB){
    return !(bitA || bitB);
}

int GateApi::test_gate_xor(int bitA, int bitB){
    return (bitA ^ bitB);
}

int GateApi::test_gate_xnor(int bitA, int bitB){
    return !(bitA ^ bitB);
}

int GateApi::test_gate_not(int bitA){
    return !(bitA);
}

int GateApi::test_gate_buffer(int bitA){
    return bitA;
}

// remove_before_flight
int GateApi::test_gate_mux(int bitA, int bitB, int bitC){
    // DON'T KNOW HOW TO IMPLEMENT THIS RIGHT NOW
    return bitA;
}
