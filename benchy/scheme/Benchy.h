#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using nano = ratio<1, 1'000'000'000>;

class Benchy{

private:
  //////////////////
  // Declarations //
  //////////////////
  chrono::high_resolution_clock::time_point tStart;
  chrono::high_resolution_clock::time_point tStop;

  vector<string> testName;
  vector<chrono::high_resolution_clock::time_point> benchmarkStartTime;
  vector<chrono::high_resolution_clock::time_point> benchmarkStopTime;
  vector<chrono::duration<int64_t, std::ratio<1, 1000000000>>> benchmarkAverageTimeDuration;

  string currentOperation;
  int currentOperationIndex = 0;
  chrono::high_resolution_clock::time_point tempStartTime;
  chrono::high_resolution_clock::time_point tempStopTime;

  void printLastTestInMicroseconds();
  void printLastTestInNanoseconds();

  // Returns -1 if it doesn't exist, and returns the position if it exists
  int checkIfOperationAlreadyExists(string operationName);

public:
  //////////////////
  // Declarations //
  //////////////////
  void startTimer(string operationName);
  void stopTimer();
  void calculateAverage();

  // will print in microseconds is no arguments are provided
  void printLastTest(string timeUnit = "us");

  // cout all values in JSON format
  void finalizeBenchmark();

  // Initialize with default values
  Benchy(){
    // No default values
  };
};

//////////////////////////
// Function definitions //
//////////////////////////
void Benchy::startTimer(string operationName){
  currentOperation = operationName;
  currentOperationIndex = checkIfOperationAlreadyExists(operationName);

  if(currentOperationIndex == -1){
    testName.push_back(currentOperation);
    tStart = chrono::high_resolution_clock::now();
    benchmarkStartTime.push_back(tStart);

  } else {
    tempStartTime = chrono::high_resolution_clock::now();

  }

}

void Benchy::stopTimer(){
  tStop = chrono::high_resolution_clock::now();

  if(currentOperationIndex == -1){
    benchmarkStopTime.push_back(tStop);

  } else {
    tempStopTime = tStop;

  }

  calculateAverage();

}

void Benchy::calculateAverage(){

  if(currentOperationIndex == -1){
    chrono::duration<int64_t, std::ratio<1, 1000000000>> currentTimeSpan = benchmarkStopTime.back() - benchmarkStartTime.back();
    benchmarkAverageTimeDuration.push_back(currentTimeSpan);

    cout << currentOperationIndex << endl;
    cout << currentTimeSpan.count() << endl << endl;

  } else {
    chrono::duration<int64_t, std::ratio<1, 1000000000>> currentTimeSpan = (tempStopTime - tempStartTime);
    chrono::duration<int64_t, std::ratio<1, 1000000000>> previousTimeSpan = (benchmarkStopTime[currentOperationIndex] - benchmarkStartTime[currentOperationIndex]);

    cout << currentOperationIndex << endl;
    cout << currentTimeSpan.count() << endl;
    cout << previousTimeSpan.count() << endl << endl;

    benchmarkAverageTimeDuration[currentOperationIndex] = ((currentTimeSpan + previousTimeSpan)/2);

  }
}

void Benchy::printLastTest(string timeUnit /* = "us"*/){
  if(timeUnit == "us") {
    printLastTestInMicroseconds();

  } else if(timeUnit == "ns") {
    printLastTestInNanoseconds();

  }
}

void Benchy::printLastTestInMicroseconds(){
  auto timeSpan = chrono::duration_cast<chrono::microseconds>(benchmarkStopTime.back() - benchmarkStartTime.back());
  cout << timeSpan.count();
}

void Benchy::printLastTestInNanoseconds(){
  auto timeSpan = chrono::duration_cast<chrono::nanoseconds>(benchmarkStopTime.back() - benchmarkStartTime.back());
  cout << timeSpan.count();
}

int Benchy::checkIfOperationAlreadyExists(string operationName){
  vector<string>::iterator it;
  it = find(testName.begin(), testName.end(), operationName);

  if (it != testName.end()) {
    int index = distance(testName.begin(), it);
    return index;

  } else {
    return -1;

  }

}


void Benchy::finalizeBenchmark(){
  for(int i=0; i<benchmarkAverageTimeDuration.size(); ++i){
    cout << benchmarkAverageTimeDuration[i].count() << endl;
  }
}
