#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree(int value) {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
  }
};

class Node {
    public:
    int diameter;
    int height;
};

Node dfs(BinaryTree *tree) {
    if(!tree)
        return Node{0,0};
    Node leftData = dfs(tree->left);
    Node rightData = dfs(tree->right);
    int longestPathThroughRooot = leftData.height+rightData.height;
    int maxDiameterSoFar = max(leftData.diameter,rightData.diameter);
    int currentDiameter = max(longestPathThroughRooot,maxDiameterSoFar);
    int currentHeight = max(leftData.height,rightData.height)+1;
    return Node{currentDiameter,currentHeight};
}

int binaryTreeDiameter(BinaryTree *tree) {
    return dfs(tree).diameter;
}