/*************************************************************************
	> File Name: BinaryStdIn.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Jan 2015 08:14:15 PM CST
 ************************************************************************/

#include "BinaryStdIn.h"

BinaryStdIn::BinaryStdIn(string filename) {
    open(filename);
}

bool BinaryStdIn::open(string filename)
{
    fin.open(filename.c_str(), std::ios::binary);
    if (!fin.is_open()) { 
        cout << "Error opening file" << endl; 
        exit (1);
    }
    fillBuffer();
    return true;
}

bool BinaryStdIn::fillBuffer() {
    char ch;
    fin >> ch;
    buffer = ch;
    N = 8;
}

bool BinaryStdIn::readBool() {
    N--;
    bool bit = ((buffer >> N) & 1) == 1;
    if (N == 0) fillBuffer();
    
    #ifdef DEBUG
        cout << "Function readBool() return : " << bit << endl;
    #endif

    return bit;
}

char BinaryStdIn::readChar() {
    if(N == 8) {
        char x = buffer;
        fillBuffer();
        return x;
    }

    char x = buffer;
    x <<= (8-N);
    int oldN = N;
    fillBuffer();
    N = oldN;
    
    unsigned char tmp = (unsigned char)buffer;
    x |= ( tmp >> N);
    
    #ifdef DEBUG
        cout << "Function readChar() return : " << x << endl;
    #endif

    return x;
}

int BinaryStdIn::readInt() {
    int x = 0;
    for (int i = 0; i < 4; i++) {
        char c = readChar();
        x <<= 8;
        x |= c;        
    }

    #ifdef DEBUG
        cout << "Function readInt() return : " << x << endl;
    #endif

    return x;
}

void BinaryStdIn::close() {
    fin.close();
}
