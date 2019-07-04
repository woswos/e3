#include <iostream>
#include <fstream>
#include "base.h"

#include "oleg.h"


int main(int argc, char const *argv[]) {

    Scheme scheme;

    try
    {

        CiphertextBit a("1"), b("0");

        scheme.consoleLog("Testing 'nand gate' with " + a.str() + " and " + b.str());

        scheme.startTimer();
        auto c = gate_nand(a, b);
        scheme.addTiming("gate_nand", scheme.stopTimer());

        scheme.consoleLogln(", result: " + std::to_string(scheme.getTiming("gate_nand")) + " nanoseconds");


        return 0;
    }
    catch (...)
    {
        scheme.consoleErrorLog("Exception");
        return 1;
    }

}
