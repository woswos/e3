#include <iostream>
#include <fstream>

#include "oleg.h"


Key CiphertextBit::key;

Key::Key()
{
    std::ifstream in("eval.key");
    if ( !in ) throw "Cannot open eval key";
    in >> k;
}
