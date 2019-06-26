#pragma once

#include <iostream>

class Benchy
{
public:
    Benchy();
    virtual ~Benchy();
    virtual void gate_operation() = 0;
};
