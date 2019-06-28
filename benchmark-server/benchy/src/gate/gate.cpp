#include "gate.h"
#include <iostream>
#include <functional>
#include <string>

int GateApi::benchmark(GateApi* schemePtr){

    // Runs GateApi::init() and GateApi::generateKeySet()
    GateApi::base_benchmark();

    //enum Gate { AND, NAND, OR, NOR, XOR, XNOR, MUX, NOT, BUFFER};
    //string gateNames[] = { "AND...", "NAND...", "OR...", "NOR...", "XOR...", "XNOR...", "MUX...", "NOT...", "BUFFER...",};

    GateApi::consoleLog("Fresh ciphertext tests");
    for (size_t i = 0; i < 2; i++) {

        GateApi::test_gate_cycle_fresh_ciphertext("gate_and_fresh", schemePtr, &GateApi::EvalAnd, &GateApi::test_gate_and);

        //std::cout << "\n";
    }

    //GateApi::test_gate_cycle_recursive_ciphertext("gate_and_recursive", schemePtr, &GateApi::EvalAnd, &GateApi::test_gate_and);

    return 1;
}

int GateApi::test_gate_cycle_recursive_ciphertext(
                            std::string gate_name_s,
                            GateApi* schemePtr,
                            void* (GateApi::*gate_func_name)(void*, void*),
                            int (GateApi::*test_gate_func_name)(int, int)
                            ){


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

    void *encryptedBitOnePtr = GateApi::Encrypt(testBitOne);
    void *encryptedBitZeroPtr = GateApi::Encrypt(testBitZero);

    void *result1 = 0;
    void *result2 = 0;
    void *result3 = 0;
    void *result4 = 0;

    int testResult1, testResult2, testResult3, testResult4;

    // Test 0 and 0
    GateApi::startTimer();
    result1 = ((*schemePtr).*gate_func_name)(encryptedBitZeroPtr, encryptedBitZeroPtr);
    GateApi::addTiming(gate_name_s, GateApi::stopTimer());

    // Test 0 and 1
    GateApi::startTimer();
    result2 = ((*schemePtr).*gate_func_name)(encryptedBitZeroPtr, encryptedBitOnePtr);
    GateApi::addTiming(gate_name_s, GateApi::stopTimer());

    // Test 1 and 0
    GateApi::startTimer();
    result3 = ((*schemePtr).*gate_func_name)(encryptedBitOnePtr, encryptedBitZeroPtr);
    GateApi::addTiming(gate_name_s, GateApi::stopTimer());

    // Test 1 and 1
    GateApi::startTimer();
    result4 = ((*schemePtr).*gate_func_name)(encryptedBitOnePtr, encryptedBitOnePtr);
    GateApi::addTiming(gate_name_s, GateApi::stopTimer());

    // Test 0 and 0
    testResult1 = ((*schemePtr).*test_gate_func_name)(testBitZero, testBitZero);
    // Test 0 and 1
    testResult2 = ((*schemePtr).*test_gate_func_name)(testBitZero, testBitOne);
    // Test 1 and 0
    testResult3 = ((*schemePtr).*test_gate_func_name)(testBitOne, testBitZero);
    // Test 1 and 1
    testResult4 = ((*schemePtr).*test_gate_func_name)(testBitOne, testBitOne);

    testResult1 = GateApi::compare(GateApi::Decrypt(result1), testResult1);
    testResult2 = GateApi::compare(GateApi::Decrypt(result2), testResult2);
    testResult3 = GateApi::compare(GateApi::Decrypt(result3), testResult3);
    testResult4 = GateApi::compare(GateApi::Decrypt(result4), testResult4);

    // Return zero if any test is not succesfull
    if((!testResult1)||(!testResult2)||(!testResult3)||(!testResult4)){
        GateApi::consoleErrorLog("An error occured during " + gate_name_s + " test");
        return 0;
    }

    GateApi::consoleLog("Timing for " + gate_name_s + " is: " + std::to_string(GateApi::getTiming(gate_name_s)) + " microsecs");

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
