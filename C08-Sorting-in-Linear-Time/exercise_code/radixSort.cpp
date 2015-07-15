#include <random>
#include <cmath>
#include <iostream>
#include <chrono>
#include <utility>

using namespace std;
/*
 *  The RandInt class is adapted from the code segments in 
 *  The C++ Programming Language, 4th Edition, Bjarne S., P130
 *
 */
class RandInt{
public:
    // range [low, high]
    RandInt(int low, int high): ge(chrono::system_clock::now().time_since_epoch().count()),dist(low, high) {}
    int operator()() {return dist(ge);}
private:
    minstd_rand ge;
    uniform_int_distribution<int> dist;
};


class RadixSort{
public:
    RadixSort(int n, int powValue);
    ~RadixSort(){}
    void printData();
    void sort();
private:
    int size;
    int digitNum;
    vector<int> sortData;
    vector<pair<int, int>> dataCopy;
    void countingSortDigit();
};


RadixSort::RadixSort(int n, int powValue): size(n), digitNum(powValue), sortData(vector<int>(n)), dataCopy(vector<pair<int, int>>(n)){
    RandInt rnd{0, (int)pow(n, powValue) - 1};
    for(auto & num: sortData){
        num = rnd();   
    }
}

void RadixSort::printData(){
   for(auto & num: sortData){
        cout << num << " ";
    }
    cout << endl;
}

void RadixSort::sort(){
    for(int i = 0; i < size; ++i){
        dataCopy[i] = make_pair(i, sortData[i]);
    }
    for(int i = 1; i <= digitNum; ++i){
        countingSortDigit();
    }
    vector<int> auxData(sortData.begin(), sortData.end());

    for(int i = 0; i < size; ++i){
        sortData[i] = auxData[dataCopy[i].first];
    } 
}

void RadixSort::countingSortDigit(){
    vector<pair<int, int>> digitData(size);
    for(int i = 0; i < size; ++i){
        digitData[i] = make_pair(i, dataCopy[i].second % size);
        dataCopy[i].second /= size;
    }
    
    vector<int> countArray(size);
    for(auto & digit: digitData){
        ++countArray[digit.second];
    }

   for(int i = 1; i < size; ++i){
       countArray[i] += countArray[i-1];
   }
   
   vector<pair<int, int>> auxData(dataCopy.begin(), dataCopy.end());
   for(int i = size - 1; i >= 0; --i){
        int curIdx = --countArray[digitData[i].second];
        dataCopy[curIdx] = auxData[digitData[i].first];
   }
   
}

int main(){
    RadixSort rst{25, 3};
    rst.printData();
    rst.sort();
    rst.printData();
}
