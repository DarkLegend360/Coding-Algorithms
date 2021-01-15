#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int T=1;

struct Node {
    char value[20];
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(char value[]) {
    struct Node *myNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(myNode->value,value);
    myNode->left=NULL;
    myNode->right=NULL;
    return myNode;
}

bool isLeafNode(struct Node *root) {
    if(!root->left && !root->right)
        return true;
    return false;
}

void setAndPrint(struct Node *root,int state) {
    if(state==1) {
        printf("%s=T%d\n",root->left->value,T-1);
        return;
    }
    printf("T%d=%s%s%s\n",T,root->left->value,root->value,root->right->value);
    strcpy(root->value,"");
    strcat(root->value,"T");
    char tmp[5];
    sprintf(tmp, "%d", T++);
    strcat(root->value,tmp);
}

void generateIntermediateCode(struct Node *root,struct Node *base) {
    if(!root)
        return;
    generateIntermediateCode(root->left,base);
    generateIntermediateCode(root->right,base);
    if(!root->left || !root->right)
        return;
    if(root!=base)
        setAndPrint(root,0);
    else
        setAndPrint(root,1);
}



void main() {
    struct Node *root = newNode("=");
    root->left=newNode("x");
    root->right=newNode("-");
    root->right->left=newNode("+");
    root->right->left->left=newNode("a");
    root->right->left->right=newNode("/");
    root->right->left->right->left=newNode("b");
    root->right->left->right->right=newNode("c");
    root->right->right=newNode("/");
    root->right->right->left=newNode("*");
    root->right->right->left->left=newNode("e");
    root->right->right->left->right=newNode("f");
    root->right->right->right=newNode("f");
    generateIntermediateCode(root,root);
}





// x=a+b*c/d;
    // struct Node *root = newNode("=");
    // root->left=newNode("x");
    // root->right=newNode("+");
    // root->right->left=newNode("a");
    // root->right->right=newNode("/");
    // root->right->right->left=newNode("*");
    // root->right->right->left->left=newNode("b");
    // root->right->right->left->right=newNode("c");
    // root->right->right->right=newNode("d");