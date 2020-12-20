#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
    public:
    int value;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int value) {
      this->value=value;
      this->left=NULL;
      this->right=NULL;
  }
};

void getInorderTraversal(BinaryTree *root,vector<BinaryTree *> &arr) {
	if(!root)
		return;
	getInorderTraversal(root->left,arr);
	arr.push_back(root);
	getInorderTraversal(root->right,arr);
}

void linkNodes(vector<BinaryTree *> &arr) {
	for(int i=0;i<arr.size()-1;i++) {
		arr[i]->right=arr[i+1];
		arr[i+1]->left=arr[i];
	}
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
	vector<BinaryTree *> arr;
	getInorderTraversal(root,arr);
	linkNodes(arr);
    return arr[0];
}

int main() {
    BinaryTree *root = new BinaryTree(5);
    root->left = new BinaryTree(3);
    root->left->left = new BinaryTree(2);
    root->left->right = new BinaryTree(4);
    root->right = new BinaryTree(7);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(8);

    BinaryTree *newNode = flattenBinaryTree(root);
    while(newNode) {
        cout<<newNode->value<<" ";
        newNode=newNode->right;
    }
    cout<<endl;
    return 0;
}