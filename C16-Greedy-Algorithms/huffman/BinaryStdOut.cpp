/*************************************************************************
	> File Name: BinaryStdOut.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Jan 2015 09:18:56 PM CST
 ************************************************************************/

#include "BinaryStdOut.h"
#include<iostream>
using namespace std;

BinaryStdOut::BinaryStdOut(string filename) {
    open(filename);
}

bool BinaryStdOut::open(string filename) {
    fout.open(filename.c_str(), ios::out|ios::binary);
    if (!fout.is_open()) { 
        cout << "Error opening file" << endl; 
        exit (1);
    }
}

void BinaryStdOut::clearBuffer() {
    if(N == 0) return;
    if (N > 0) buffer <<= (8 - N);
    fout << buffer;
    N = 0;
    buffer = 0;
}

void BinaryStdOut::writeBit(bool bit) {
    buffer <<= 1;
    if (bit) buffer |= 1;
    N++;
    if (N == 8) clearBuffer();
}

void BinaryStdOut::writeChar(char ch) {
    if (N == 0) {
        fout << ch;
        return;        
    }

    for (int i = 0; i < 8; i++) {
        bool bit = ((ch >> (8 - i - 1)) & 1 ) == 1;
        writeBit(bit);        
    }
}

void BinaryStdOut::write(bool x) {
    writeBit(x);
}

void BinaryStdOut::write(char x) {
    writeChar(x);
}

void BinaryStdOut::write(int x) {
    writeChar((x >> 24) & 0xff);
    writeChar((x >> 16) & 0xff);
    writeChar((x >> 8) & 0xff);
    writeChar((x >> 0) & 0xff);
}

void BinaryStdOut::flush() {
    clearBuffer();
    fout.flush();
}

void BinaryStdOut::close() {
    flush();
    fout.close();
    cout << "-------------------- BinaryStdOut Writing Closing --------------------" << endl;
}
