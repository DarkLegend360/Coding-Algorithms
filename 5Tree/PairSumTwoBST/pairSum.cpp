#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node *left,*right;
    Node(int val) {
        value=val;
        left=NULL;
        right=NULL;
    }
};

// void findPair(Node *BST1 , Node *BST2,int x) {
//     if(BST1==NULL || BST2==NULL) return;
//     if((BST1->value+BST2->value) == x) {
//         cout<<"FOUND:"<<BST1->value<<" "<<BST2->value<<endl;
//         return;
//     }
//     if((BST1->value+BST2->value) > x) {
//         if(BST1->value<BST2->value) 
//             findPair(BST1 ,BST2->left,x);
//         else   
//             findPair(BST1->left ,BST2,x);
//     } else {
//         if(BST1->value<BST2->value)
//             findPair(BST1->right ,BST2,x);
//         else
//             findPair(BST1 ,BST2->right,x);
//     }
// }

void trav(Node *root,vector<int> &res)
 {
     if(root==NULL) return;
     trav(root->left,res);
     res.push_back(root->value);
     trav(root->right,res);
 }

int main() {
    Node *BST1 = new Node(5);
    BST1->left = new Node(3);
    BST1->left->left = new Node(2);
    BST1->left->right = new Node(4);
    BST1->right = new Node(7);
    BST1->right->left = new Node(6);
    BST1->right->right = new Node(8);

    Node *BST2 = new Node(10);
    BST2->left = new Node(6);
    BST2->left->left = new Node(3);
    BST2->left->right = new Node(8);
    BST2->right = new Node(15);
    BST2->right->left = new Node(11);
    BST2->right->right = new Node(18);

    int x=19;
    //findPair(BST1,BST2,x);

    vector<int> arr1,arr2;
    trav(BST1,arr1);
    trav(BST2,arr2);
    int i=0,j=arr2.size()-1;
    while(i!=arr1.size() && j>=0) {
        if((arr1[i]+arr2[j])==x) {
            cout<<"FOUND:"<<arr1[i]<<" "<<arr2[j]<<endl;
            i++;
        } else if((arr1[i]+arr2[j])>x) 
            j--;
        else
            i++;
    }
    return 0;
}