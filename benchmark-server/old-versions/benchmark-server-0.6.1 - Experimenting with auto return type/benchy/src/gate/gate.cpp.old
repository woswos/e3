#include "gate.h"
#include <iostream>
#include <functional>
#include <string>

struct Key { int k = 1; };

class CiphertextBit
{

    private:
        int x = 0;
	static Key key;

    public:
        CiphertextBit() {};

        CiphertextBit(std::string v): x(std::stoi(v)) {}
        std::string str() const { return std::to_string(x); }

        CiphertextBit nand(CiphertextBit b) const
        {
            CiphertextBit r;
            r.x = 1 & ~(x & b.x);
            return r;
        }

};

inline CiphertextBit gate_nand(CiphertextBit a, CiphertextBit b){ return a.nand(b); }
inline CiphertextBit gate_not(CiphertextBit a){ return gate_nand(a,a); }
inline CiphertextBit gate_and(CiphertextBit a, CiphertextBit b){ return gate_not(gate_nand(a,b)); }


int GateApi::benchmark(GateApi* schemePtr){

    // Runs GateApi::init() and GateApi::generateKeySet()
    GateApi::base_benchmark();

    //enum Gate { AND, NAND, OR, NOR, XOR, XNOR, MUX, NOT, BUFFER};
    //string gateNames[] = { "AND...", "NAND...", "OR...", "NOR...", "XOR...", "XNOR...", "MUX...", "NOT...", "BUFFER...",};

/*
    for (size_t i = 0; i < 1000000; i++) {
        std::cout << GateApi::Decrypt(GateApi::EvalAnd(GateApi::Encrypt(0), GateApi::Encrypt(0))) << "\n";
        std::cout << GateApi::Decrypt(GateApi::EvalAnd(GateApi::Encrypt(0), GateApi::Encrypt(1))) << "\n";
        std::cout << GateApi::Decrypt(GateApi::EvalAnd(GateApi::Encrypt(1), GateApi::Encrypt(0))) << "\n";
        std::cout << GateApi::Decrypt(GateApi::EvalAnd(GateApi::Encrypt(1), GateApi::Encrypt(1))) << "\n";
    }
*/
    GateApi::test_gate_manual_single(0,1);

    /*
    GateApi::consoleLog("Fresh ciphertext tests");
    for (size_t i = 0; i < 2; i++) {

        GateApi::test_gate_cycle_fresh_ciphertext("gate_nand_fresh", schemePtr, &GateApi::EvalNand, &GateApi::test_gate_nand);

        //std::cout << "\n";
    }
*/
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

int GateApi::test_gate_manual_single(int bitA, int bitB){

    void *encryptedBitOnePtr = GateApi::Encrypt(bitA);
    void *encryptedBitZeroPtr = GateApi::Encrypt(bitB);

    void *result1;
    void *result2;

    CiphertextBit a(std::to_string(bitA)), b(std::to_string(bitB));

    CiphertextBit result1o;
    CiphertextBit result2o;

    GateApi::consoleLog("Testing 'nand gate' with " + std::to_string(bitA) + " and " + std::to_string(bitB));



    for (size_t i = 0; i < 1000; i++) {
        for (size_t i = 0; i < 1000000; i++) {
            GateApi::startTimer();
            result1 = GateApi::EvalNand(encryptedBitOnePtr, encryptedBitZeroPtr);
            result2 = GateApi::EvalNand(encryptedBitZeroPtr, encryptedBitOnePtr);
            GateApi::addTiming("nanda", GateApi::stopTimer());

            GateApi::startTimer();
            result1 = GateApi::EvalNand(result1, result2);
            result2 = GateApi::EvalNand(result2, result1);
            GateApi::addTiming("nanda", GateApi::stopTimer());

            GateApi::startTimer();
            result1 = GateApi::EvalNand(result1, result2);
            result2 = GateApi::EvalNand(result2, result1);
            GateApi::addTiming("nanda", GateApi::stopTimer());

            GateApi::startTimer();
            result1 = GateApi::EvalNand(result1, result2);
            result2 = GateApi::EvalNand(result2, result1);
            GateApi::addTiming("nanda", GateApi::stopTimer());

        }

        for (size_t i = 0; i < 1000000; i++) {
            GateApi::startTimer();
            result1o = gate_and(a, b);
            result2o = gate_and(b, a);
            GateApi::addTiming("nandb", GateApi::stopTimer());

            GateApi::startTimer();
            result1o = gate_and(result1o, result2o);
            result2o = gate_and(result2o, result1o);
            GateApi::addTiming("nandb", GateApi::stopTimer());

            GateApi::startTimer();
            result1o = gate_and(result1o, result2o);
            result2o = gate_and(result2o, result1o);
            GateApi::addTiming("nandb", GateApi::stopTimer());

            GateApi::startTimer();
            result1o = gate_and(result1o, result2o);
            result2o = gate_and(result2o, result1o);
            GateApi::addTiming("nandb", GateApi::stopTimer());

        }

        std::cout << "still running" << "\n";
    }



    GateApi::consoleLog("Difference: " + std::to_string(GateApi::getTiming("nanda")-GateApi::getTiming("nanda")) + " nanosecs");

    //GateApi::consoleLog("Timing for 'nand gate' is: " + std::to_string(GateApi::getTiming("nand")) + " nanosecs");

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

    GateApi::consoleLog("Timing for " + gate_name_s + " is: " + std::to_string(GateApi::getTiming(gate_name_s)) + " nanosecs");

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
