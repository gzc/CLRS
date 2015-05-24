/*************************************************************************
	> File Name: second-smallest.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sun May 24 09:32:14 2015
 ************************************************************************/
#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int v;
    Node *left;
    Node *right;
    bool dir;    // 0 mean left, 1 mean right
    Node() : v(-1),left(nullptr),right(nullptr){}
    Node(int _v, bool d) : v(_v),left(nullptr),right(nullptr),dir(d){}
};


int second_smallest_element(int arr[], int n)
{
    queue<Node*> q;
    for(int i = 0;i < n;i++)
    {
        Node *new_node = new Node(arr[i], 0);
        q.push(new_node);
    }
    
    Node *root(nullptr);
    while(!q.empty())
    {
        int size = q.size();
        if(size == 1)
        {
            root = q.front();
            break;
        }
        for(int i = 0;i < size;i += 2)
        {
            if(i == size - 1)
            {
                Node *n1 = q.front(); q.pop();
                q.push(n1);
                break;
            } else {
                Node *n1 = q.front(); q.pop();
                Node *n2 = q.front(); q.pop();
                int smaller = 0;
                bool dir;
                if(n1 -> v <= n2 -> v)
                {
                    smaller = n1->v;
                    dir = false;
                } else {
                    smaller = n2->v;
                    dir = true;
                }
                
                Node *new_node = new Node(smaller,dir);
                new_node->left = n1;
                new_node->right = n2;
                q.push(new_node);
            }
        }
    }
    
    int minium = root->v;
    int result(INT_MAX);
    while(root)
    {
        if(root->left && root->right)
        {
            result = min( (root->left->v ^ root->right->v ^ minium), result);
            root = root->dir == true ? root->right : root->left;
        } else break;
    }
    return result;
}


int main() {
    int arr[8] = {3,4,1,0,7,-2,-10,100};
    int result = second_smallest_element(arr, 8);
    cout << result << endl;
    
    return 0;
}