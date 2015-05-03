
/*************************************************************************
	> File Name: main.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sun May  3 00:05:14 2015
 ************************************************************************/

#include "BSTree.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    BSTree<int> intBST;
    cout << "Constructing empty BST\n";
    cout << "BST " << (intBST.isEmpty()?"is":"is not") << "empty\n";
    
    int number;
    for (;;)
    {
        cout << "Item to insert (-999 to stop):";
        cin >> number;
        if (number == -999) break;
        intBST.insert(number);
    }
    intBST.inorder(cout);
    cout << endl;
    intBST.graph(cout);
    
    //测试find
    for (;;)
    {
        cout << "Item to find (-999 to stop):";
        cin >> number;
        if (number == -999) break;
        bool found = intBST.find(number);
        cout << boolalpha << found << endl;
    }
    
    //测试remove
    for (;;)
    {
        cout << "Item to remove (-999 to stop):";
        cin >> number;
        if (number == -999) break;
        intBST.remove(number);
        cout << endl;
        intBST.graph(cout);
        cout << endl;
    }
    intBST.inorder(cout);
    return 0;
}
