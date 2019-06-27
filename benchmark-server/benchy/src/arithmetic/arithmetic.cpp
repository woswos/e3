#include "arithmetic.h"
#include <iostream>

int ArithmeticApi::benchmark(ArithmeticApi* schemePtr){

    ArithmeticApi::base_benchmark();

    void *result = 0;

        int a = 1;
        int b = 2;

        void *valA = ArithmeticApi::encrypt(a);
        void *valB = ArithmeticApi::encrypt(b);

        void *valC = ArithmeticApi::arithmetic_add(valA, valB);

        std::cout << ArithmeticApi::decrypt(valC) << "\n";

    return 1;
}
