#include "gate.h"

//void Gate::benchmark(){
//    std::cout << "Test started" << std::endl;
//}

void Gate::gate_and(Bit& a, Bit& b, Bit& result){
    result.value = (a.value && b.value);
}

void Gate::gate_nand(Bit& a, Bit& b, Bit& result){
    result.value = !(a.value && b.value);
}

void Gate::gate_or(Bit& a, Bit& b, Bit& result){
    result.value = (a.value || b.value);
}

void Gate::gate_nor(Bit& a, Bit& b, Bit& result){
    result.value = !(a.value || b.value);
}

void Gate::gate_xor(Bit& a, Bit& b, Bit& result){
    result.value = !(a.value ^ b.value);
}

void Gate::gate_xnor(Bit& a, Bit& b, Bit& result){
    result.value = !(a.value ^ b.value);
}

void Gate::gate_not(Bit& a, Bit& result){
    result.value = !(a.value);
}

void Gate::gate_buffer(Bit& a, Bit& result){
    result.value = a.value;
}
