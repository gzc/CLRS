#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <cassert>

using namespace std;

class QuickSort{
public:
    QuickSort(){}
    ~QuickSort(){}
    void qsort(vector<int> &data);

    bool isSorted(int start, int end, vector<int> & data);
private:
    void sortHelper(int start, int end, vector<int> & data);    
    int hoarePartition(int start, int end, vector<int> & data);

    void threeSortHelper(int start, int end, vector<int> & data);
    pair<int, int> threeWayPartition(int start, int end, vector<int> & data);
    pair<int, int> fastThreePartition(int start, int end, vector<int> & data);

    int getRandom(int start, int end);
};

void QuickSort::qsort(vector<int> & data){
    threeSortHelper(0, data.size() - 1, data);
}

void QuickSort::sortHelper(int start, int end, vector<int> & data){
    if(start < end){
        int pivot = hoarePartition(start, end, data);
        sortHelper(start, pivot - 1, data);
        sortHelper(pivot + 1, end, data);
    }
}

void QuickSort::threeSortHelper(int start, int end, vector<int> & data){
    if(start < end){
        int randomIdx = getRandom(start, end);
        swap(data[start], data[randomIdx]);
        auto bound = fastThreePartition(start, end, data); 
        threeSortHelper(start,bound.first - 1, data);
        threeSortHelper(bound.second + 1, end, data);  
    }
}

/*/////////////////////////////////////////
 *
 *  Partition Algorithm Block
 *
 */////////////////////////////////////////


/*
 * Modified Hoare Partition, which stops scanning on equal elements to avoid 
 * the occurence of worst case O(n^2)
 * 
 * Ref: Programming Perls 2nd Edition, Jon Bentley
 */
int QuickSort::hoarePartition(int start, int end, vector<int> & data){
    int pivot = data[start];
    int i = start;
    int j = end + 1;
    while(true){
        do{
            ++i;
        } while( i <= end && data[i] < pivot);
        
        do{
            --j; 
        } while (data[j] > pivot);    
        
        if(i > j){
            break;
        }
        swap(data[i], data[j]);
    } 
    swap(data[start], data[j]);
    return j;
}

/**
 *  Ref:Algorithms, 4th Edition by Robert S. and Kevin W. 
 */
pair<int, int> QuickSort::threeWayPartition(int start, int end, vector<int> & data){
    int pivot = data[start];
    int low = start;
    int high = end;
    int i = low + 1;
 
    while(i <= high){
        if(data[i] < pivot){
            swap(data[i++], data[low++]);
        } else if (data[i] > pivot){
            swap(data[i], data[high--]);
        } else {
            ++i;
        }
    }
    return make_pair(low, high); 
}

/**
 * The three way partition above does extra swaps for elements not equal to pivot.
 * The fast three way partition below does extra swaps for elements equal to pivot to i.
 * This algorithm does fewer swaps when the number of elements equal to pivot is smaller.
 *
 * Ref:Algorithms, 4th Edition by Robert S. and Kevin W. 
 *   
 */


pair<int, int> QuickSort::fastThreePartition(int start, int end, vector<int> & data){
	int i = start, j = end + 1;
        int p = start, q = end + 1;
        int v = data[start];
        while(true){
            while(data[++i] < v){
	        if(i == end){
                     break;
                }
            }
	    while(data[--j] > v){
                if(j == start){
                     break;
                }
            }
            if(i == j && data[i] == v){
                swap(data[++p], data[i]);
            }
            if(i >= j) break;
            swap(data[i], data[j]);
            if(data[i] == v){
                swap(data[++p], data[i]);
            }
            if(data[j] == v){
                swap(data[--q], data[j]);
            }
        }

        i = j + 1;
        for(int k = start; k <= p; ++k){
	    swap(data[k], data[j--]);
        }
        for(int k = end; k>= q; --k){
            swap(data[k], data[i++]);
        }
        return make_pair(j + 1, i - 1);
}

/*/////////////////////////////////////////
 *
 *  Utility Function Block
 *
 */////////////////////////////////////////


int QuickSort::getRandom(int start, int end){
    srand(time(NULL));
    return rand() % (end - start + 1) + start;
}

bool QuickSort::isSorted(int start, int end, vector<int> & data){
    for(int i = start + 1; i <= end; ++i){
        if(data[i] < data[i-1]){
            return false;
        }
    }
    return true;

}


int main(){
    vector<int> test1 {0};
    vector<int> test2 {-1, 3, 2, 4,-10, 100};
    QuickSort solver;
    solver.qsort(test1);
    solver.qsort(test2);
    assert(solver.isSorted(0, test1.size()-1, test1));
    assert(solver.isSorted(0, test2.size()-1, test2));
}
