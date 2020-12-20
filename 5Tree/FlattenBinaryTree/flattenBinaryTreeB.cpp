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

void connectNodes(BinaryTree *left,BinaryTree *right) {
    left->right=right;
    right->left=left;
}

vector<BinaryTree *> helper(BinaryTree *root) {
    BinaryTree *leftMost,*rightMost;
    if(!root->left)
        leftMost=root;
    else {
        vector<BinaryTree *> leftAndRightMostNodes = helper(root->left);
        connectNodes(leftAndRightMostNodes[1],root);
        leftMost=leftAndRightMostNodes[0];
    }
    if(!root->right)
        rightMost=root;
    else {
        vector<BinaryTree *> leftAndRightMostNodes = helper(root->right);
        connectNodes(root,leftAndRightMostNodes[0]);
        rightMost=leftAndRightMostNodes[1];
    }
    return {leftMost,rightMost};
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
    return helper(root)[0];
}
 
 int main() {
    BinaryTree *root = new BinaryTree(5);
    root->left = new BinaryTree(3);
    root->left->left = new BinaryTree(2);
    root->left->right = new BinaryTree(4);
    root->right = new BinaryTree(7);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(8);
    BinaryTree *result = flattenBinaryTree(root);
    while(result) {
        cout<<result->value<<" ";
        result=result->right;
    }
    cout<<endl;
    return 0;
}