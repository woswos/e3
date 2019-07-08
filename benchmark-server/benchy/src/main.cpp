#include <iostream>
#include <string>
#include <vector>

//#include "circuits/circuit.h"

#include "oleg.h"

#include "gate/gate_benchmark.h"

using std::string;

using Bit = CiphertextBit;

//string f2s(string n) { string r; std::ifstream(n) >> r; return r; }

int main(int argc, char const *argv[]) {

    try
    {
        Bit bitOne("1"), bitZero("0");

        unsigned time = 100; // ms

        for ( auto g : gates ){

            // in microseconds
            cout << names[g] << " " << test<Bit>( g, bitOne, bitZero, time ) << '\n';
        }

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
