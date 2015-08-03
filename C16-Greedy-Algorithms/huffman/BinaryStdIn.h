/*************************************************************************
	> File Name: BinaryStdIn.h
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Jan 2015 08:05:13 PM CST
 ************************************************************************/

#ifndef _BINARYSTDIN_H
#define _BINARYSTDIN_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class BinaryStdIn
{
    ifstream fin;
    char buffer;
    int N;

    bool fillBuffer();

public:
	BinaryStdIn(){};
    BinaryStdIn(string filename);
    bool open(string filename);
    bool readBool();
    char readChar();
    int readInt();

    void close();
};


#endif
