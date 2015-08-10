/*************************************************************************
	> File Name: travelsal.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Mon Aug 10 19:04:08 2015
 ************************************************************************/
#include<iostream>
using namespace std;

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    struct tree_t *parent;
    int key;
    tree_t() {left = 0; right = 0; parent = 0;}
};

void print_tree(tree_t *tree) {
    tree_t *prev;
    prev = 0;
    
    while (tree) {
        if (prev == tree->parent) {
            cout << tree->key << endl;
            prev = tree;
            tree = tree->left  ? tree->left :
            tree->right ? tree->right :
            tree->parent;
        } else if (prev == tree->left && tree->right) {
            prev = tree;
            tree = tree->right;
        } else {
            prev = tree;
            tree = tree->parent;
        }
    }
}


int main() {
    tree_t root;
    root.key = 1;
    
    tree_t left;
    left.key = 2;
    
    tree_t right;
    right.key = 3;
    
    root.left = &left;
    root.right = &right;
    left.parent = &root;
    right.parent = &root;
    
    print_tree(&root);

    return 0;
}
