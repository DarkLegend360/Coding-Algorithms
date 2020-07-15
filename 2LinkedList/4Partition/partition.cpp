#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *next=NULL;
    Node(int val) {
        value=val;
    }
};

int main() {
    // vector<int> inputs = {2,4,6,7,9,1,4,5,8,2,3,4};
    vector<int> inputs = {3,5,8,5,10,2,1};
    Node *head=new Node(-1);
    Node *ptr=head;
    for(auto x:inputs) {
        ptr->next=new Node(x);
        ptr=ptr->next;
    }
    int x=5;
    Node *before_head = new Node(-1);
    Node *after_head = new Node(-1);
    Node *before = before_head;
    Node *after = after_head;
    ptr=head->next;
    while(ptr!=NULL) {
        if(ptr->value<x) {
            before->next=ptr;
            before=before->next;
        } else {
            after->next=ptr;
            after=after->next;
        }
        ptr=ptr->next;
        after->next=NULL;
    }
    if(before_head->next==NULL) {
        ptr=after_head->next;
    } else {
        before->next=after_head->next;
        ptr=before_head->next;
    }
    //Display
    
    while(ptr!=NULL) {
        cout<<ptr->value<<endl;
        ptr=ptr->next;
    }
}