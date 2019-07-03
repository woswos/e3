#include "base.h"
#include <iostream>
#include <map>
#include <time.h>
#include <random>
#include <functional>
#include <chrono>


void Scheme::base_benchmark(){

    Scheme::Init();

    Scheme::GenerateKeySet();

}

void Scheme::consoleLog(string message){
    std::cout << message << std::endl;
}

void Scheme::consoleErrorLog(string message){
    std::cout << "######" << std::endl;
    std::cout << "ERROR:" << std::endl;
    std::cout << message << std::endl;
    std::cout << "######" << std::endl << std::endl;
}

void Scheme::addTiming(string key, long long value){
    if ( Scheme::timings.find(key) == Scheme::timings.end() ) {
        Scheme::timings.insert({key, value});

    } else {
        long long temp = Scheme::timings[key];
        Scheme::timings[key] = ((value + temp)/2);

    }
}


long long Scheme::getTiming(string key){

    return Scheme::timings[key];
}


void Scheme::startTimer(){

    Scheme::tempTime = std::chrono::high_resolution_clock::now();;
}


long long Scheme::stopTimer(){

    std::chrono::_V2::system_clock::time_point currentTime = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - Scheme::tempTime).count();
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
