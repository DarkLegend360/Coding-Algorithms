#include <bits/stdc++.h>
using namespace std;

/*
1.Normal BST Insertion
2.Update Current Node Height
3.Check for Imbalance
4.Perform Rotation and Height Update if Imbalance

*/

class Node {
    public:
    int value;
    int height;
    Node *left,*right;

    Node(int value) {
        this->value=value;
        this->height=0;
        this->left=NULL;
        this->right=NULL;
    }
};

int getHeight(Node* root) {
    if(!root)
        return -1;
    return root->height;
}

int getBalanceFactor(Node *root) {
    if(!root)
        return 0;
    return getHeight(root->left)-getHeight(root->right);
}

Node *leftRotation(Node* root) {
    Node *rightNode = root->right;
    root->right=rightNode->left;
    rightNode->left=root;

    root->height=1+max(getHeight(root->left),getHeight(root->right));
    rightNode->height=1+max(getHeight(rightNode->left),getHeight(rightNode->right));
    return rightNode;
}

Node *rightRotation(Node* root) {
    Node *leftNode = root->left;
    root->left=leftNode->right;
    leftNode->right=root;

    root->height=1+max(getHeight(root->left),getHeight(root->right));
    leftNode->height=1+max(getHeight(leftNode->left),getHeight(leftNode->right));
    return leftNode;
}

Node* insert(Node *root, int value) {
    if(!root)
        return new Node(value);
    else if(value<root->value)
        root->left=insert(root->left, value);
    else if(value>root->value)
        root->right=insert(root->right, value);
    else 
        return root;

    root->height=1+max(getHeight(root->left),getHeight(root->right));

    int balance = getBalanceFactor(root);

    if(balance>1) {
        if(value<root->left->value)
            return rightRotation(root);
        else {
            root->left=leftRotation(root->left);
            return rightRotation(root);
        }
    } else if(balance<-1) {
        if(value>root->right->value)
            return leftRotation(root);
        else {
            root->right=rightRotation(root->right);
            return leftRotation(root);
        }
    }
    return root;
}

Node* getInOrderSuccessor(Node* root) {
    Node *prev=root;
    while(root) {
        prev=root;
        root=root->left;
    }
    return prev;
}

Node* remove(Node* root, int value) {
    if(!root)
        return root;
    else if(value<root->value)
        root->left=remove(root->left, value);
    else if(value>root->value)
        root->right=remove(root->right, value);
    else {
        if(!root->left || !root->right) {
            Node* tempNode = root->left?root->left:root->right;
            if(!tempNode) {
                tempNode=root;
                root=NULL;
            } else
                root=tempNode;
            delete tempNode;
        } else {
            Node *inOrderSuccessor = getInOrderSuccessor(root->right);
            root->value=inOrderSuccessor->value;
            root->right=remove(root->right, inOrderSuccessor->value);
        }
    }
    if(!root)
        return root;
    root->height=1+max(getHeight(root->left),getHeight(root->right));

    int balance = getBalanceFactor(root);

    if(balance>1) {
        if(getBalanceFactor(root->left)>=0)
            return rightRotation(root);
        else {
            root->left=leftRotation(root->left);
            return rightRotation(root);
        }
    } else if(balance<-1) {
        if(getBalanceFactor(root->right)<=0)
            return leftRotation(root);
        else {
            root->right = rightRotation(root->left);
            return leftRotation(root);
        }
    }
    return root;
}

void inOrderTraversal(Node *root) {
    if(!root)
        return;
    inOrderTraversal(root->left);
    cout<<(root->value)<<" ";
    inOrderTraversal(root->right);
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 25};
    Node* root = NULL;
    for(int i=0;i<arr.size();i++)
        root = insert(root, arr[i]);
    //remove(root, 10);
    inOrderTraversal(root);
    cout<<"\n";
    return 0;
}