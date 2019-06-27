#include "base.h"
#include <iostream>
#include <map>
#include <time.h>
#include <random>
#include <functional>

void Scheme::base_benchmark(){

    Scheme::Init();

    Scheme::GenerateKeySet();

}


void Scheme::addTiming(string key, long int value){
    if ( Scheme::timings.find(key) == Scheme::timings.end() ) {
        Scheme::timings.insert({key, value});

    } else {
        long int temp = Scheme::timings[key];
        Scheme::timings[key] = ((value + temp)/2);

    }
}


int Scheme::getTiming(string key){

    return Scheme::timings[key];
}


void Scheme::startTimer(){

    Scheme::tempTime = clock();
}


long int Scheme::stopTimer(){

    time_t currentTime = clock();

    long int duration = static_cast<long int> (currentTime - Scheme::tempTime);
    return duration;
}


bool Scheme::randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    return gen();
}

bool Scheme::compare(int valueA, int valueB) {
    if(valueA == valueB){
        return true;
    } else {
        return false;
    }
}
