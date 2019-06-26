#pragma once

#include "benchy.h"
#include "bit.h"
#include <iostream>

class Encrypt : public Benchy
{
public:
    //void benchmark();

    void encrypt(Bit& a, Bit& b, Bit& result);

};
