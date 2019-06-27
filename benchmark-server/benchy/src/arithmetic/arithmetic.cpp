#include "arithmetic.h"
#include <iostream>

int ArithmeticApi::benchmark(ArithmeticApi* schemePtr){

    ArithmeticApi::base_benchmark();

    void *result = 0;

        int a = 1;
        int b = 2;

        void *valA = ArithmeticApi::Encrypt(a);
        void *valB = ArithmeticApi::Encrypt(b);

        void *valC = ArithmeticApi::EvalAdd(valA, valB);

        std::cout << ArithmeticApi::Decrypt(valC) << "\n";

    return 1;
}
