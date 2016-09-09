#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = nullptr;
    }
};

class NumArray {
    
    SegmentTreeNode* root;
    
    SegmentTreeNode* build(int start, int end, const vector<int>& A) {
        if (start > end) return nullptr;
        else if (start == end) {
            SegmentTreeNode *tree = new SegmentTreeNode(start, end, A[start]);
            return tree;
        } else {
            SegmentTreeNode *left = build(start, (start+end)/2, A);
            SegmentTreeNode *right = build((start+end)/2+1, end, A);
            SegmentTreeNode *tree = new SegmentTreeNode(start, end, left->sum + right->sum);
            tree -> left = left;
            tree -> right = right;
            return tree;
        }
    }
    
    void modify(SegmentTreeNode *root, int i, int val) {
        if (root->start == root->end) {
            root->sum = val;
            return;
        }
        if (i <= root->left->end) modify(root->left, i, val);
        else modify(root->right, i, val);
        root->sum = root->left->sum + root->right->sum;
    }
    
    int query(SegmentTreeNode *root, int i, int j) {
        if (root->start == root->end) return root->sum;
        if (root->start == i && root->end == j) return root->sum;
        
        if(j <= root->left->end) {
            return query(root->left, i, j);
        } else if (i >= root->right->start) {
            return query(root->right, i, j);
        } else {
            return query(root->left, i, root->left->end) + query(root->right, root->right->start, j);
        }
    }
    
public:
    NumArray(vector<int> &nums) {
        root = build(0, nums.size()-1, nums);
    }
    
    void update(int i, int val) {
        modify(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(root, i, j);
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(1, 10);
    cout << numArray.sumRange(1, 2) << endl;
}