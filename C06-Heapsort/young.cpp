/*************************************************************************
	> File Name: young.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Tue Jun 23 20:05:44 2015
 ************************************************************************/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int EXTRACT_MIN(vector<vector<int> > &young)
{
    int minimum = young[0][0];
    int i(0),j(0);
    
    while(i < young.size() && j < young[0].size())
    {
        int cur = young[i][j];
        int ori(i),orj(j);
        int right(INT_MAX),down(INT_MAX);
        
        if(i < young.size()-1) down = young[i+1][j];
        if(j < young[0].size()-1) right = young[i][j+1];
        
        if(right == INT_MAX && down == INT_MAX)
        {
            young[i][j] = INT_MAX;
            break;
        }
        else if(down <= right)
            i++;
        else
            j++;
            
        swap(young[i][j], young[ori][orj]);
    }
    
    return minimum;
}

void INSERT(vector<vector<int> > &young, int v)
{
    int i = young.size()-1;
    int j = young[0].size()-1;
    young[i][j] = v;
    
    while(i >= 0 && j >= 0)
    {
        int left(INT_MIN),up(INT_MIN);
        
        if(i > 0) up = young[i-1][j];
        if(j > 0) left = young[i][j-1];
        
        if(v >= up && v >= left)
            break;
        else if(v < up)
        {
            swap(young[i][j], young[i-1][j]);
            i--;
        } else {
            swap(young[i][j], young[i][j-1]);
            j--;
        }
    }
}

bool EXIST(vector<vector<int> > &young, int v)
{
    int i(young.size()-1),j(0);
    
    while(i >= 0 && j < young[0].size())
    {
        cout << i << " " << j << endl;
        if(young[i][j] == v)
            return true;
        
        if(young[i][j] < v)
            j++;
        else
            i--;
    }
    
    return false;
}

void print_young(vector<vector<int> > &young)
{
    for(int i = 0;i < young.size();i++)
    {
        for(int j = 0;j < young[0].size();j++)
        {
            cout << young[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    
    int arr1[4] = {2,3,12,INT_MAX};
    int arr2[4] = {4,8,16,INT_MAX};
    int arr3[4] = {5,9,INT_MAX,INT_MAX};
    int arr4[4] = {14,INT_MAX,INT_MAX,INT_MAX};
    
    vector<int> v1(arr1,arr1+4);
    vector<int> v2(arr2,arr2+4);
    vector<int> v3(arr3,arr3+4);
    vector<int> v4(arr4,arr4+4);
    
    vector<vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    
    for(int i  = 0;i < 9;i++)
        cout << EXTRACT_MIN(v) << endl;
    for(int i  = 0;i < 9;i++)
        INSERT(v, i);
    print_young(v);
    cout << EXIST(v, 8) << endl;



    return 0;
}
