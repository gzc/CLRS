#include <iostream>
using namespace std;

int find(int *a, int len, int n)
{
    int left(0),right(len),mid = (left+right)/2;
    while(left <= right)
    {
        if(n > a[mid]) left = mid + 1;
        else if(n < a[mid]) right = mid - 1;
        else return mid;
        mid = (left + right)/2;
    }
    return left;
}

int main()
{
    int n, a[100], c[100], i, j, len;
    cin >> n;
    
    for(int i = 0;i < n;i++)
        cin >> a[i];
    c[0] = -1;
    c[1] = a[0];
    len = 1;
        
    for(i = 1;i <= n;i++)
    {
        j = find(c, len, a[i]);
        c[j] = a[i];
        if(j > len)
            len = j;
    }
    
    cout << len << endl;
    return 0;
}