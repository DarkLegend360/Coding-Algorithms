#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value, BinaryTree *parent) {
  this->value = value;
  this->left = NULL;
  this->right = NULL;
}
};

void iterativeInOrderTraversal(BinaryTree *tree) {
    stack<BinaryTree *> st;
    BinaryTree *currentNode = tree;
    while(!st.empty() || currentNode) {
        while(currentNode) {
            st.push(currentNode);
            currentNode=currentNode->left;
        }
        currentNode=st.top();
        st.pop();
        cout<<currentNode->value<<endl;
        currentNode=currentNode->right;
    }
}

int main() {
    BinaryTree *root = new BinaryTree(1, NULL);
    root->left = new BinaryTree(2, root);
    root->left->left = new BinaryTree(4, root->left);
    root->left->left->right = new BinaryTree(9, root->left->left);
    root->right = new BinaryTree(3, root);
    root->right->left = new BinaryTree(6, root->right);
    root->right->right = new BinaryTree(7, root->right);
    iterativeInOrderTraversal(root);
    return 0;
}