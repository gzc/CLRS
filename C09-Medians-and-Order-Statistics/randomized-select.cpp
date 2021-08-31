#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition(vector<int>& arr, int l, int r) {
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}
    
int kthSmallest(vector<int>& arr, int l, int r, int k) {
    int pos = randomPartition(arr, l, r);
    if (pos - l == k - 1) {
        return arr[pos];
    } else if (pos - l > k - 1) {
        return kthSmallest(arr, l, pos - 1, k);
    } else {
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
}

int kthSmallest(vector<int>& arr, int k) {
    // TODO: Validate k is in valid range. 
    return kthSmallest(arr, 0, arr.size() - 1, k);
}

int main() {
    vector<int>v{3,4,2,5,1};
    cout << kthSmallest(v, 1) << endl;
    cout << kthSmallest(v, 2) << endl;
    cout << kthSmallest(v, 3) << endl;
    cout << kthSmallest(v, 4) << endl;
    cout << kthSmallest(v, 5) << endl;
}
