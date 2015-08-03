/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Jan 2015 10:49:50 PM CST
 ************************************************************************/

#include<iostream>
#include "../BinaryStdIn.h"
#include "../BinaryStdOut.h"
using namespace std;

int main()
{
    string filename = "data";
    BinaryStdOut binaryStdOut;
    binaryStdOut.open(filename);
    
    
    binaryStdOut.write('h');
    binaryStdOut.write('e');
    binaryStdOut.write('l');
    binaryStdOut.write('l');
    binaryStdOut.write('o');

    binaryStdOut.write(true);
    binaryStdOut.write(false);

    binaryStdOut.write(30);
    binaryStdOut.write('p');


    binaryStdOut.close();

    BinaryStdIn binaryStdIn(filename);


    cout << binaryStdIn.readChar() << endl;
    cout << binaryStdIn.readChar() << endl;
    cout << binaryStdIn.readChar() << endl;
    cout << binaryStdIn.readChar() << endl;
    cout << binaryStdIn.readChar() << endl;
    cout << binaryStdIn.readBool() << endl;
    cout << binaryStdIn.readBool() << endl;
    cout << binaryStdIn.readInt() << endl;
    cout << binaryStdIn.readChar() << endl;
    return 0;
}
