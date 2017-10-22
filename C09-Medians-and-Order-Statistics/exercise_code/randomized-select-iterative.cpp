/*************************************************************************
 > File Name: randomized-select-iterative.cpp
 > Author: Louis1992
 > Mail: zhenchaogan@gmail.com
 > Blog: http://gzc.github.io
 > Created Time: Sun May 24 11:46:39 2015
 ************************************************************************/
#include<iostream>
#include <cassert>
using namespace std;

class Solution {
    
    int partition(int arr[], int l, int r) {
        int x = arr[r], i = l;
        for(int j = l; j <= r - 1; j++) {
            if (arr[j] <= x) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }
    
    int randomPartition(int arr[], int l, int r) {
        int n = r-l+1;
        int pivot = rand() % n;
        swap(arr[l + pivot], arr[r]);
        return partition(arr, l, r);
    }
    
public:
    
    int kthSmallest(int arr[], int l, int r, int k) {
        int originalK = k;
        while (k > 0 && k <= r - l + 1) {
            int pos = randomPartition(arr, l, r);
            if (pos-l == k-1) {
                return arr[pos];
            } else if(pos-l > k-1) {
                r = pos-1;
            } else {
                l = pos+1;
                k = originalK-l;
            }
        }
        return INT_MAX;
    }
    
};

int main() {
    int arr[7] = {10, 100, 2, 4, 1, -2, 8};
    Solution s;
    assert(s.kthSmallest(arr, 0, 6, 1) == -2);
    assert(s.kthSmallest(arr, 0, 6, 2) == 1);
    assert(s.kthSmallest(arr, 0, 6, 3) == 2);
    assert(s.kthSmallest(arr, 0, 6, 4) == 4);
    assert(s.kthSmallest(arr, 0, 6, 5) == 8);
    assert(s.kthSmallest(arr, 0, 6, 6) == 10);
    assert(s.kthSmallest(arr, 0, 6, 7) == 100);
}
