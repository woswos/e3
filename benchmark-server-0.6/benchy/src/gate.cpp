#include "gate.h"
#include <iostream>

int GateApi::benchmark(){

    GateApi::base_benchmark();

    void *result = 0;

    for (size_t i = 0; i < 100; i++) {

        void *bitA = GateApi::encrypt(GateApi::randomBool());
        void *bitB = GateApi::encrypt(GateApi::randomBool());

        GateApi::startTimer();
        result = GateApi::gate_and(bitA, bitB);
        GateApi::addTiming("gate_and", GateApi::stopTimer());
    }


    GateApi::startTimer();
    GateApi::decrypt(result);
    GateApi::addTiming("decrypt", GateApi::stopTimer());

    GateApi::cleanup();


    std::cout << GateApi::getTiming("gate_and") << " microsecs \n";
    std::cout << GateApi::getTiming("decrypt") << " microsecs \n";

    return 1;
}
