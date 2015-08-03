/*************************************************************************
	> File Name: HUFFMAN.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Jan 2015 11:48:32 PM CST
 ************************************************************************/

#include "HUFFMAN.h"
#include<iostream>
using namespace std;

HUFFMAN::HUFFMAN() {
}

HUFFMAN::~HUFFMAN() {
	if(!huffman_Tree) destroy(huffman_Tree);
}

void HUFFMAN::buildTree(string &data, string filename) {
    
    map<char, int> frequency;
    for(string::iterator it = data.begin(); it != data.end(); it++) {
        frequency[*it]++;
    }

    #ifdef DEBUG   
        cout << "-------------------- Frequencies of data --------------------" << endl;
        for(map<char, int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
            cout << it->first << "   " << it->second << endl;
        }
        cout << "-------------------- End of frequencies --------------------" << endl;
    #endif

    priority_queue<Htree *, vector<Htree *>, myComparision> pq;

    for(map<char, int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
        Htree *node = new Htree(NULL, NULL, it->second, it->first);
        pq.push(node);
    }

    while(pq.size() > 1) {
        Htree *node1 = pq.top();
        pq.pop();
        Htree *node2 = pq.top();
        pq.pop();
        Htree *node = new Htree(node1, node2, node1->weight+node2->weight, 0);
        pq.push(node);
    }

    huffman_Tree = pq.top();
    vector<bool> code;
    buildDict(huffman_Tree, code);

    #ifdef DEBUG
        cout << "-------------------- Show Encoding Dict --------------------" << endl;

        for(huffman_dict::iterator it = dict.begin(); it != dict.end(); it++) {
            cout << it->first << "    ";
            vector<bool> code = it->second;
            for(vector<bool>::iterator codeit = code.begin(); codeit != code.end(); codeit++) {
                cout << *codeit;
            }
            cout << endl;
        }

        cout << "-------------------- End of Dict --------------------" << endl;
    #endif
}

void HUFFMAN::buildDict(Htree *node, vector<bool> &code) {
    if(isLeaf(node)) {
        dict[node->ch] = code;
    } else {
        code.push_back(false);
        buildDict(node->left, code);
        code.pop_back();
        code.push_back(true);
        buildDict(node->right, code);
        code.pop_back();
    }
}


void HUFFMAN::writeTrie(Htree *node) {
    if (isLeaf(node)) {
        binaryStdOut->write(true);
        binaryStdOut->write(node->ch);
        return; 
    }
    binaryStdOut->write(false);
    writeTrie(node->left);
    writeTrie(node->right);
}

void HUFFMAN::encode(string &data, string filename) {
    cout << "-------------------- Begin Encoding Data : " << filename << " --------------------" << endl;
    buildTree(data, filename);

    binaryStdOut = new BinaryStdOut(filename);

    //first of all, write our huffman tree
    writeTrie(huffman_Tree);
    
    //Then write the total length of our data
    binaryStdOut->write((int)data.length());

    //Finally, write our compressed data
    for(string::iterator it = data.begin(); it != data.end(); it++) {
        char ch = *it;
        vector<bool> code = dict[ch];
 
        for(vector<bool>::iterator codeit = code.begin(); codeit != code.end(); codeit++) {
            bool v = *codeit;
            binaryStdOut->write(v);
        }
    }
    binaryStdOut->close();
    delete binaryStdOut;
    if(!huffman_Tree) destroy(huffman_Tree);
    cout << endl << "-------------------- Finish Encoding Data --------------------" << endl;
}

Htree * HUFFMAN::readTrie() {
    bool isLeaf = binaryStdIn->readBool();
    if (isLeaf) {
        return new Htree(NULL, NULL, -1, binaryStdIn->readChar());        
    } else {
        return new Htree(readTrie(), readTrie(), -1, '\0');        
    }
}

string HUFFMAN::decode(string filename) {
	cout << endl << "-------------------- Begin Decoding Data --------------------" << endl;

    binaryStdIn = new BinaryStdIn(filename);
    
    huffman_Tree = readTrie();
    int length = binaryStdIn->readInt();
    
    string data;
    for (int i = 0; i < length; i++) {
    	Htree *x = huffman_Tree;
        while (!isLeaf(x)) {
            bool bit = binaryStdIn->readBool();
            if (bit) x = x->right;
            else x = x->left;
        }
        data += x->ch;
    } 
    
    delete binaryStdIn;
    if(!huffman_Tree) destroy(huffman_Tree);
    cout << endl << "-------------------- Finish Decoding Data --------------------" << endl;
    
    return data;
}

/*
* delete all the nodes
* prevent memory leak
*/
void HUFFMAN::destroy(Htree *node) {
    if(node->left) destroy(node->left);
    if(node->right) destroy(node->right);
    delete node;
}

