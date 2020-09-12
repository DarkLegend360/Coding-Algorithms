#include <bits/stdc++.h>
using namespace std;

class BST {
    public:
    int value;
    BST *left,*right;
    BST(int val) {
        value=val;
        left=NULL;
        right=NULL;
    }
    BST &insert(int val) {
        BST *currentNode = this;
        while(true) {
            if(val<currentNode->value) {
                if(currentNode->left)
                    currentNode=currentNode->left;
                else {
                    currentNode->left=new BST(val);
                    break;
                }
            } else {
                if(currentNode->right)
                    currentNode=currentNode->right;
                else {
                    currentNode->right=new BST(val);
                    break;
                }
            }
        }
        return *this;
    }
    bool contains(int val) {
        BST *currentNode=this;
        while(currentNode) {
            if(val<currentNode->value)
                currentNode=currentNode->left;
            else if(val>currentNode->value)
                currentNode=currentNode->right;
            else
                return true;
        }
        return false;
    }
    int getMinValue() {
        if(left)
            return left->getMinValue();
        return value;
    }
    BST &remove(int val,BST *parentNode = NULL) {
        BST *currentNode = this;
        while(currentNode) {
            if(val <currentNode->value) {
                parentNode=currentNode;
                currentNode=currentNode->left;
            }
            else if(val>currentNode->value){
                parentNode=currentNode;
                currentNode=currentNode->right;
            } else {
                if(currentNode->left && currentNode->right) {
                    currentNode->value=currentNode->right->getMinValue();
                    currentNode->right->remove(currentNode->value,currentNode);
                } else if(parentNode==NULL) {
                    if(currentNode->left) {
                        currentNode->value=currentNode->left->value;
                        currentNode->right=currentNode->left->right;
                        currentNode->left=currentNode->left->left;
                    } else if(currentNode->right) {
                        currentNode->value=currentNode->right->value;
                        currentNode->left=currentNode->right->left;
                        currentNode->right=currentNode->right->right;
                    }//else case 
                }
                else if(parentNode->left==currentNode)
                    parentNode->left=(currentNode->left)?currentNode->left:currentNode->right;
                else if(parentNode->right==currentNode)
                    parentNode->right=(currentNode->left)?currentNode->left:currentNode->right;
                break;
            }
        }
        return *this;
    }
};

int main(){
    return 0;
}