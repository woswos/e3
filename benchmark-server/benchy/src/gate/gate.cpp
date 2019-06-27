#include "gate.h"
#include <iostream>
#include <functional>
#include <string>

int GateApi::benchmark(GateApi* schemePtr){

    // Runs GateApi::init() and GateApi::generateKeySet()
    GateApi::base_benchmark();

    //enum Gate { AND, NAND, OR, NOR, XOR, XNOR, MUX, NOT, BUFFER};
    //string gateNames[] = { "AND...", "NAND...", "OR...", "NOR...", "XOR...", "XNOR...", "MUX...", "NOT...", "BUFFER...",};

    std::cout << "Fresh ciphertext tests" << "\n";

    for (size_t i = 0; i < 10; i++) {

        GateApi::test_gate_cycle_fresh_ciphertext("gate_and", schemePtr, &GateApi::EvalAnd, &GateApi::test_gate_nand);

        //GateApi::test_gate_cycle_fresh_ciphertext("gate_nand", schemePtr, &GateApi::EvalNand, &GateApi::test_gate_nand);

        //GateApi::test_gate_cycle_fresh_ciphertext("gate_or", schemePtr, &GateApi::EvalOr, &GateApi::test_gate_or);

        std::cout << "\n";
    }

    return 1;
}

int GateApi::test_gate_cycle_fresh_ciphertext(
                            std::string gate_name_s,
                            GateApi* schemePtr,
                            void* (GateApi::*gate_func_name)(void*, void*),
                            int (GateApi::*test_gate_func_name)(int, int)
                            ){

    int testBitOne = 1;
    int testBitZero = 0;

    void *bitOne = GateApi::Encrypt(testBitOne);
    void *bitZero = GateApi::Encrypt(testBitZero);

    void *result1 = 0;
    void *result2 = 0;
    void *result3 = 0;
    void *result4 = 0;

    int testResult1, testResult2, testResult3, testResult4;

    GateApi::startTimer();
    //result1 = GateApi::gate_nand(bitZero, bitZero);
    result1 = ((*schemePtr).*gate_func_name)(bitZero, bitZero);
    GateApi::addTiming(gate_name_s, GateApi::stopTimer());

    GateApi::startTimer();
    result2 = ((*schemePtr).*gate_func_name)(bitZero, bitOne);
    GateApi::addTiming(gate_name_s, GateApi::stopTimer());

    GateApi::startTimer();
    result3 = ((*schemePtr).*gate_func_name)(bitOne, bitZero);
    GateApi::addTiming(gate_name_s, GateApi::stopTimer());

    GateApi::startTimer();
    result4 = ((*schemePtr).*gate_func_name)(bitOne, bitOne);
    GateApi::addTiming(gate_name_s, GateApi::stopTimer());

    testResult1 = ((*schemePtr).*test_gate_func_name)(testBitZero, testBitZero);
    testResult2 = ((*schemePtr).*test_gate_func_name)(testBitZero, testBitOne);
    testResult3 = ((*schemePtr).*test_gate_func_name)(testBitOne, testBitZero);
    testResult4 = ((*schemePtr).*test_gate_func_name)(testBitOne, testBitOne);

    testResult1 = GateApi::compare(GateApi::Decrypt(result1), testResult1);
    testResult2 = GateApi::compare(GateApi::Decrypt(result2), testResult2);
    testResult3 = GateApi::compare(GateApi::Decrypt(result3), testResult3);
    testResult4 = GateApi::compare(GateApi::Decrypt(result4), testResult4);
    /*
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
    */
    std::cout << "Timing for " << gate_name_s << " is: " << GateApi::getTiming(gate_name_s) << " microsecs" << "\n";

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
