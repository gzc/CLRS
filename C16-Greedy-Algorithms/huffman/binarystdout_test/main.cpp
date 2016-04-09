/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Jan 2015 08:33:11 PM CST
 ************************************************************************/

#include<iostream>
#include "../BinaryStdOut.h"
using namespace std;

int main()
{
    string filename = "data";

    BinaryStdOut binaryStdOut(filename);

    //write 8 true
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(true);

    //write 8 false
    binaryStdOut.write(false);
    binaryStdOut.write(false);
    binaryStdOut.write(false);
    binaryStdOut.write(false);
    binaryStdOut.write(false);
    binaryStdOut.write(false);
    binaryStdOut.write(false);
    binaryStdOut.write(false);

    //4 true , 4 false
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(true);
    binaryStdOut.write(false);
    binaryStdOut.write(false);
    binaryStdOut.write(false);
    binaryStdOut.write(false);

    binaryStdOut.write('a');
    binaryStdOut.write(false);
    binaryStdOut.write(512);

    binaryStdOut.close();

    return 0;
}

