/*************************************************************************
	> File Name: randomized-select-iterative.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sun May 24 11:46:39 2015
 ************************************************************************/
#include<iostream>
using namespace std;

class Solution {
    
    int partition(int arr[], int l, int r)
    {
        int x = arr[r], i = l;
        for(int j = l; j <= r - 1; j++)
        {
            if (arr[j] <= x)
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }
    
    int randomPartition(int arr[], int l, int r)
    {
        int n = r-l+1;
        int pivot = rand() % n;
        swap(arr[l + pivot], arr[r]);
        return partition(arr, l, r);
    }
    
public:
    
    int kthSmallest(int arr[], int l, int r, int k)
    {
        cout << l << " " << r << " " << k << endl;
        while (k > 0 && k <= r - l + 1)
        {
            int pos = randomPartition(arr, l, r);
            
            if (pos-l == k-1)
            return arr[pos];
            else if(pos-l > k-1)
            {
                r = pos-1;
            }
            else
            {
                l = pos+1;
                k = k-pos+l-1;
            }
        }
        return INT_MAX;
    }
    
};

int main()
{
    int arr[5] = {2,4,1,-2,8};
    Solution s;
    cout << s.kthSmallest(arr, 0, 4, 2);
}