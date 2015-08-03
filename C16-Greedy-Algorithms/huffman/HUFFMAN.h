/*************************************************************************
	> File Name: HUFFMAN.h
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Jan 2015 11:20:02 PM CST
 ************************************************************************/

#include <queue>
#include <algorithm>
#include <fstream>
#include <map>
#include <bitset>
#include <cassert>
#include "BinaryStdIn.h"
#include "BinaryStdOut.h"

using namespace std;

#ifndef _HUFFMAN_H
#define _HUFFMAN_H

struct Htree {
    Htree *left;
    Htree *right;
    int weight;
    char ch;
    Htree() {left = right = NULL; weight = 0;ch = 0;}
    Htree(Htree *l, Htree *r, int v, char c) {left = l; right = r; weight = v; ch = c;}   
};


// is the node a leaf node?
static inline bool isLeaf(Htree *node) {
    assert ( (node->left == NULL && node->right == NULL) || (node->left != NULL && node->right != NULL) );
    return (node->left == NULL && node->right == NULL);
}

class myComparision  
{  
public:  
    bool operator () (const Htree* t1, const Htree* t2) {  
        return t1->weight> t2->weight;  
    }
};  

class HUFFMAN {
    typedef map<char, vector<bool> > huffman_dict;

    Htree *huffman_Tree;
    huffman_dict dict;
    BinaryStdOut *binaryStdOut;
    BinaryStdIn *binaryStdIn;

    void buildTree(string &data, string filename);
    void buildDict(Htree *node, vector<bool> &code);
    void destroy(Htree *node);
    void writeTrie(Htree *node);
    Htree *readTrie();

public:
    
    HUFFMAN();
    ~HUFFMAN();
    void encode(string &data, string filename);
    string decode(string filename);
};

#endif
