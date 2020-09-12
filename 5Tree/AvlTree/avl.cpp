#include <bits/stdc++.h>
using namespace std;

class AVL {
    public:
        int value;
        AVL *left,*right;
        int height;

        AVL(int value) {
            this->value=value;
            left=NULL;
            right=NULL;
            height=1;
        }
};



AVL *insert(AVL *currentNode , int val) {
    if(currentNode==NULL)
        return new AVL(val);
    if(val < currentNode->value)
        return insert(currentNode->left,val);
    else if(val>currentNode->value)
        return insert(currentNode->right,val);
    else 
        return currentNode;
    
    currentNode->height=1+max()
}

int main() {

    return 0;
}


