#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;
  BinaryTree(int value) { this->value = value; }
};

void helper(BinaryTree *root, BinaryTree *node, bool &isFound, BinaryTree *&result) {
	if(!root)
		return;
	helper(root->left,node,isFound,result);
	if(isFound){
		result=root;
		isFound=false;
	}
	if(root==node)
		isFound=true;
	helper(root->right,node,isFound,result);
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
    if(!tree)
		return NULL;
	BinaryTree *result = NULL;
	bool isFound=false;
	helper(tree,node,isFound,result);
	return result;
}

int main() {
    BinaryTree *root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->parent = root;
    root->right = new BinaryTree(3);
    root->right->parent = root;
    root->left->left = new BinaryTree(4);
    root->left->left->parent = root->left;
    root->left->right = new BinaryTree(5);
    root->left->right->parent = root->left;
    root->left->left->left = new BinaryTree(6);
    root->left->left->left->parent = root->left->left;
    auto node = root->left->right;
    auto expected = root;
    auto actual = findSuccessor(root, node);
    cout<<(expected == actual)<<endl;
    return 0;
}