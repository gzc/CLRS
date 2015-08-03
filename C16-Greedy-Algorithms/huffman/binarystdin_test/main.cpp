/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Jan 2015 08:33:11 PM CST
 ************************************************************************/

#include<iostream>
#include "../BinaryStdIn.h"
using namespace std;

int main()
{
    string filename = "data";

    BinaryStdIn binaryStdIn(filename);

    cout << binaryStdIn.readInt() << endl;

    binaryStdIn.close();

    return 0;
}

