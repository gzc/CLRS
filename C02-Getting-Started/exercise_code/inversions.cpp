//  Created by wander on 16/5/14.
//  Copyright © 2016年 W4anD0eR96. All rights reserved.
//  采用左闭右开的区间描述方式

#include "bits/stdc++.h"
using namespace std;

void MergeWithCountInversions(vector<int>& v, int p, int q, int r, int& cnt) {
  int n1 = q - p, n2 = r - q;
  vector<int> L, R;
  for (int i = 0; i < n1; ++i) L.push_back(v[p + i]);
  for (int i = 0; i < n2; ++i) R.push_back(v[q + i]);
  L.push_back(INT_MAX); R.push_back(INT_MAX);
  
  int i = 0, j = 0;
  for (int k = p; k < r; ++k) {
    //   i      n1    j    n2
    //   |      |     |    |
    // |--------)|---------）
    // 若此时发生L[i] > R[j]，则由于L[0..i) < R[j]且R[0..j) < R[j]
    // 故与R[j]构成逆序对的元素是L[i..n1)
    if (L[i] <= R[j]) { v[k] = L[i]; i += 1; }
    else { v[k] = R[j]; j += 1; cnt += n1 - i;
      { for (int u = i; u < n1; ++u) cout << "(" << L[u] << "," << R[j - 1] << "), "; } // Print Inversions
    }
  }
}

void MergeSort(vector<int>& v, int p, int r, int& cnt) {
  if (p >= r - 1) return;
  int q = (p + r) >> 1;
  MergeSort(v, p, q, cnt);
  MergeSort(v, q, r, cnt);
  MergeWithCountInversions(v, p, q, r, cnt);
}

int main(int argc, const char * argv[]) {
  vector<int> v = { 31, 41, 59, 26, 41, 58 };
  int cntInversions = 0;
  
  cout << "v: ";
  for (auto i : v) cout << i << " ";
  cout << endl;
  
  cout << "Total inversions are: ";
  MergeSort(v, 0, (int)v.size(), cntInversions);
  cout << endl;
  cout << "Whose amount is: " << cntInversions << "." << endl;
  
  return 0;
}
