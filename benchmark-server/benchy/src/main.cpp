#include <iostream>
#include <string>
#include <vector>
#include "benchmark.h"

#include "oleg.h"

using Bit = CiphertextBit;

int main(int argc, char const *argv[]) {

    Bit a("1"), b("0");

    auto c = gate_nand(a, b);


    try
    {
        unsigned time = 100; // ms


        for ( auto g : gates ){
            cout << names[g] << " " << test<Bit>( g, a, b, time ) << '\n';
        }


        //cout << "N... "; validateGates<BNUint<1>, BNBit>(_0_En, _1_En);

    }
    catch (string e)
    {
        cout << "Error: " << e << "\n";
    }
    catch (...)
    {
        cout << "exception\n";
    }

}
