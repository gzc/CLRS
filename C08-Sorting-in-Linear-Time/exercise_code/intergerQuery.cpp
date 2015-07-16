#include <vector>
#include <cassert>
#include <stdexcept>
#include <algorithm>

using namespace std;

class IntegerQuery{
public:
    IntegerQuery(vector<int> & data);
    int countInRange(int a, int b);
private:
    vector<int> countArray;
    int k;
    bool noData;
};


IntegerQuery::IntegerQuery(vector<int> & data){
   noData = data.empty(); 
   if(!noData){
        k = *max_element(data.begin(), data.end());
        countArray = vector<int> (k + 1);
        for(auto & num: data){
            ++countArray[num];
        }
        for(int i = 1; i <= k; ++i){
            countArray[i] += countArray[i - 1];
        }
    } 
}

int IntegerQuery::countInRange(int a, int b){
    if(a > b || b < 0 || a > k || noData){
       return 0;
    }
    int sum = a <= 0 ? countArray[0] : 0;

    sum += countArray[min(k, b)] - countArray[max(0, a - 1)];
    return sum;
}

int main(){
    vector<int> test{0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
    IntegerQuery query(test);
    assert(query.countInRange(-1, 4) == 12);
    assert(query.countInRange(-2, -1) == 0);
    assert(query.countInRange(-3, 0) == 3);
    assert(query.countInRange(0,1) == 6);
}
