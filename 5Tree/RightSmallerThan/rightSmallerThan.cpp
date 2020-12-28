#include <bits/stdc++.h>
using namespace std;

class BST {
    public:
    int value;
    int leftSubtreeSize;
    BST *left;
    BST *right;
    BST(int value) {
        this->value=value;
        this->leftSubtreeSize=0;
        this->left=NULL;
        this->right=NULL;
    }
    void insert(int value,int idx,vector<int> &rightSmallerCounts,int numSmallerAtInsertTime=0) {
        if(value<this->value) {
            leftSubtreeSize++;
            if(!left) {
                left=new BST(value);
                rightSmallerCounts[idx]=numSmallerAtInsertTime;
            } else
                left->insert(value,idx,rightSmallerCounts,numSmallerAtInsertTime);
        } else {
            numSmallerAtInsertTime+=leftSubtreeSize;
            if(value>this->value)
                numSmallerAtInsertTime++;
            if(!right) {
                right=new BST(value);
                rightSmallerCounts[idx]=numSmallerAtInsertTime;
            } else 
                right->insert(value,idx,rightSmallerCounts,numSmallerAtInsertTime);
        }
    }
};

vector<int> rightSmallerThan(vector<int> arr) {
    if(!arr.size())
        return {};
    vector<int> rightSmallerCounts(arr.size());
    int lastIdx=arr.size()-1;
    BST *root = new BST(arr[lastIdx]);
    for(int idx=lastIdx-1;idx>=0;idx--)
        root->insert(arr[idx],idx,rightSmallerCounts);
    return rightSmallerCounts;
}

int main() {

    return 0;
}