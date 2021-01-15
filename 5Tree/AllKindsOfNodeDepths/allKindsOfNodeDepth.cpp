#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

class TreeInfo {
    public:
    int nodeCount;
    int sumOfDepth;
    int sumOfAllDepths;
    TreeInfo(int nodeCount, int sumOfDepth, int sumOfAllDepths) {
        this->nodeCount=nodeCount;
        this->sumOfDepth=sumOfDepth;
        this->sumOfAllDepths=sumOfAllDepths;
    }
};

TreeInfo helper(BinaryTree *root) {
    if(!root)
        return TreeInfo(0,0,0);
    TreeInfo left = helper(root->left);
    TreeInfo right = helper(root->right);
    int newCount=left.nodeCount+right.nodeCount+1;
    int newDepth=left.sumOfDepth+right.sumOfDepth+newCount-1;
    int newSumOfAllDepth=left.sumOfAllDepths+right.sumOfAllDepths+newDepth;
    return TreeInfo(newCount,newDepth,newSumOfAllDepth);
}

int allKindsOfNodeDepths(BinaryTree *root) {
    if(!root)
        return 0;
    return helper(root).sumOfAllDepths;
}

int main() {
    BinaryTree *root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->left = new BinaryTree(4);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    root->left->right = new BinaryTree(5);
    root->right = new BinaryTree(3);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    int actual = allKindsOfNodeDepths(root);
    cout<<(actual == 26)<<endl;
    return 0;
}