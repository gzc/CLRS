/*************************************************************************
	> File Name: m-Josephus.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Wed Jul 15 11:49:42 2015
 ************************************************************************/
#include<iostream>
using namespace std;

struct node
{
    int no;
    node *next;
    node(int i){no = i;}
};

int main()
{
    int m,n;
    node *cur,*q,*first;
    cout<<"请输入m的初始值 m:"; cin>>m;
    cout<<"请输入人数 n:"; cin>>n;
    
    for(int i = 1;i<=n;i++)
    {
        if(i == 1)
            first = cur = new node(i);
        else
        {
            q = new node(i);
            cur->next = q;
            cur = q;
        }
    }
    
    cur->next = first;
    cur = first;
    cout<<"出列顺序为: ";
    for (int j = 1;j<=n;j++)
    {
        for(int i = 1; i < m;i++,cur=cur->next);
        cout << cur->no <<" ";
        cur->no = cur->next->no;
        q = cur->next;
        cur->next = cur->next->next;
    }
    
    cout<<endl;
    return 0;
}
