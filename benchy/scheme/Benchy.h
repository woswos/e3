#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Benchy{

private:
  //////////////////
  // Declarations //
  //////////////////
  vector<string> testName;
  vector<chrono::duration<long long, std::ratio<1, 1000000>>> benchmarkAverageTimeDuration;

  string currentOperation;
  int currentOperationIndex = 0;
  vector<chrono::high_resolution_clock::time_point> tempStartTime;
  vector<chrono::high_resolution_clock::time_point> tempStopTime;
  chrono::duration<long long, std::ratio<1, 1000000>> duration;
  chrono::duration<long long, std::ratio<1, 1000000>> previousAverage;

  // Returns -1 if it doesn't exist, and returns the position if it exists
  int checkIfOperationAlreadyExists(string operationName);

  void jsonify();

public:
  //////////////////
  // Declarations //
  //////////////////
  void startTimer(string operationName);
  void stopTimer();
  void calculateAverage();

  // will print in microseconds
  void printLastTest();

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
  }

  tempStartTime.push_back(chrono::high_resolution_clock::now());

}

void Benchy::stopTimer(){

  tempStopTime.push_back(chrono::high_resolution_clock::now());

  calculateAverage();

}

void Benchy::calculateAverage(){

  duration = chrono::duration_cast<chrono::microseconds>(tempStopTime.back() - tempStartTime.back());

  if(currentOperationIndex == -1){
    benchmarkAverageTimeDuration.push_back(duration);


    cout << "first time for '" << testName.back() << "' operation" << endl;
    cout << "current value: " << duration.count() << " ms" << endl << endl;


  } else {
    previousAverage = benchmarkAverageTimeDuration[currentOperationIndex];
    benchmarkAverageTimeDuration[currentOperationIndex] = ((duration + previousAverage)/2);


    cout << "operation index: " << currentOperationIndex << endl;
    cout << "'NOT' first time for '" << testName[currentOperationIndex] << "' operation" << endl;
    cout << "previous average: " << previousAverage.count() << " ms" << endl;
    cout << "current value: " << duration.count() << " ms" << endl;
    cout << "current average: " << benchmarkAverageTimeDuration[currentOperationIndex].count() << " ms" << endl << endl;


  }
}

void Benchy::printLastTest(){
  cout << "Duration for the last test was: " << duration.count() << " ms" << endl;
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
  cout << "{ ";
  for(int i=0; i < benchmarkAverageTimeDuration.size(); ++i){
    cout << '"' << testName[i] << '"' << " : " << benchmarkAverageTimeDuration[i].count();
      if(i != (benchmarkAverageTimeDuration.size() - 1)){
        cout << ", ";
      }
  }
  cout << " }";

}

// unused
void Benchy::jsonify(){
  cout << "{ 'results': [ [";

  for(int i=0; i < benchmarkAverageTimeDuration.size(); ++i){
    cout << "'" << testName[i] << "'";
      if(i != (benchmarkAverageTimeDuration.size() - 1)){
        cout << ", ";
      }
  }
  cout << " ], ";

  cout << " [ ";
  for(int i=0; i < benchmarkAverageTimeDuration.size(); ++i){
    cout << benchmarkAverageTimeDuration[i].count();
      if(i != (benchmarkAverageTimeDuration.size() - 1)){
        cout << ", ";
      }
  }
  cout << " ] ] }";

}
