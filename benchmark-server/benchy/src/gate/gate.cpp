#include "gate.h"
#include <iostream>

int GateApi::benchmark(){

    // Runs GateApi::init() and GateApi::generateKeySet()
    GateApi::base_benchmark();

    enum Gate { AND, NAND, OR, NOR, XOR, XNOR, MUX, NOT, BUFFER};
    string gateNames[] = { "AND...", "NAND...", "OR...", "NOR...", "XOR...", "XNOR...", "MUX...", "NOT...", "BUFFER...",};

    GateApi::test_gate_cycle();

    return 1;
}

int GateApi::test_gate_cycle(){

    int testBitOne = 1;
    int testBitZero = 0;

    void *bitOne = GateApi::encrypt(testBitOne);
    void *bitZero = GateApi::encrypt(testBitZero);

    void *result1 = 0;
    void *result2 = 0;
    void *result3 = 0;
    void *result4 = 0;

    int testResult1, testResult2, testResult3, testResult4;

    GateApi::startTimer();
    result1 = GateApi::gate_nand(bitZero, bitZero);
    GateApi::addTiming("gate_and", GateApi::stopTimer());

    GateApi::startTimer();
    result2 = GateApi::gate_nand(bitZero, bitOne);
    GateApi::addTiming("gate_and", GateApi::stopTimer());

    GateApi::startTimer();
    result3 = GateApi::gate_nand(bitOne, bitZero);
    GateApi::addTiming("gate_and", GateApi::stopTimer());

    GateApi::startTimer();
    result4 = GateApi::gate_nand(bitOne, bitOne);
    GateApi::addTiming("gate_and", GateApi::stopTimer());

    testResult1 = GateApi::test_gate_nand(testBitZero, testBitZero);
    testResult2 = GateApi::test_gate_nand(testBitZero, testBitOne);
    testResult3 = GateApi::test_gate_nand(testBitOne, testBitZero);
    testResult4 = GateApi::test_gate_nand(testBitOne, testBitOne);

    testResult1 = GateApi::compare(GateApi::decrypt(result1), testResult1);
    testResult2 = GateApi::compare(GateApi::decrypt(result2), testResult2);
    testResult3 = GateApi::compare(GateApi::decrypt(result3), testResult3);
    testResult4 = GateApi::compare(GateApi::decrypt(result4), testResult4);

    if(testResult1){
        std::cout << "Test 1 is succesfull" << "\n";
    }

    if(testResult2){
        std::cout << "Test 2 is succesfull" << "\n";
    }

    if(testResult3){
        std::cout << "Test 3 is succesfull" << "\n";
    }

    if(testResult4){
        std::cout << "Test 4 is succesfull" << "\n";
    }

    std::cout << "Timing for nand gate is: " << GateApi::getTiming("gate_and") << " microsecs" << "\n";

    return 0;
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
