#include <iostream>
#include <string>
#include <vector>
#include "benchmark.h"



using Bit = CiphertextBit;

int main(int argc, char const *argv[]) {

    //auto c = gate_nand(a, b);

    try
    {
        Bit bitOne("1"), bitZero("0");

        unsigned time = 100; // ms

        for ( auto g : gates ){
            cout << names[g] << " " << test<Bit>( g, bitOne, bitZero, time ) << '\n';
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
