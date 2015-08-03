/*************************************************************************
	> File Name: huffman_test_client.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Jan 2015 07:59:40 PM CST
 ************************************************************************/

#include<iostream>
#include "../HUFFMAN.h"
using namespace std;

int main()
{
    string data = "3248&&&^aaaaaabbbbccccdddeef";

    string filename = "compressed";
    HUFFMAN huffman;
    huffman.encode(data, filename);
    string rdata = huffman.decode(filename);
    cout << "Recover data : " << rdata << endl;

    return 0;
}
