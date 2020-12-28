#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
    public:
    int value;
    BinaryTree *left = NULL;
    BinaryTree *right = NULL;
    BinaryTree(int value) {
        this->value=value;
    }
};

void mutate(BinaryTree *root, BinaryTree *parentNode, bool isLeftNode) {
    if(!root)
        return;
    BinaryTree *left = root->left;
    BinaryTree *right = root->right;
    mutate(left,root,true);
    if(!parentNode)
        root->right=NULL;
    else if(isLeftNode) 
        root->right=parentNode->right;
    else
        if(!parentNode->right || !parentNode->right->left)
            root->right=NULL;
        else
            root->right=parentNode->right->left;
    mutate(right,root,false);
}

BinaryTree *rightSiblingTree(BinaryTree *root) {
    mutate(root,NULL,false);
    return root;
}

int main() {
    return 0;
}