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

Node* detectLoops(Node *head) {
    if(head==NULL || head->next==NULL)
        return NULL;
    Node *slow,*fast;
    slow=head->next;;
    fast=head->next->next;
    while(slow!=fast) {
        slow=slow->next;
        if(fast->next==NULL || fast->next->next==NULL)
            return NULL;
        fast=fast->next->next;
    }
    slow=head;
    while(slow!=fast) {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main() {
    vector<int> inputs = {1,2,3,4,5,6,7,8,9,10,11};
    Node *head=new Node(-1);
    Node *ptr=head;
    Node *temp;
    for(int x:inputs) {
        ptr->next=new Node(x);
        if(x==3)
            temp=ptr->next;
        ptr=ptr->next;
    }
    ptr->next=temp;
    //Loop Detection
    Node *res = detectLoops(head->next);
    if(res)
        cout<<"Result:"<<res->value<<endl;
    else
        cout<<"No Loops Detected"<<endl;
}