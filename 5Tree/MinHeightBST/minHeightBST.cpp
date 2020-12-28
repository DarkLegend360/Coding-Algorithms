#include <bits/stdc++.h>
using namespace std;

class BST {
    public:
    int value;
    BST *left;
    BST *right;

    BST(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }

    void insert(int value) {
        if (value < this->value) {
            if (left == NULL) 
                left = new BST(value);
            else
                left->insert(value);
        } else {
            if (right == NULL) 
                right = new BST(value);
            else 
                right->insert(value);
        }
    }
};

BST *helper(vector<int> arr,int leftIdx,int rightIdx) {
    if(leftIdx>rightIdx)
        return NULL;
    int midIdx = leftIdx + (rightIdx-leftIdx)/2;
    BST *root=new BST(arr[midIdx]);
    root->left=helper(arr,leftIdx,midIdx-1);
    root->right=helper(arr,midIdx+1,rightIdx);
    return root;
}

BST *minHeightBst(vector<int> arr) {
    if(!arr.size())
        return NULL;
    return helper(arr,0,arr.size()-1);
}