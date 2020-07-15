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
    vector<int> inputs = {2,4,6,7,9,1,4,5,8,2,3,4};
    Node *head=new Node(-1);
    Node *ptr=head;
    for(auto x:inputs) {
        ptr->next=new Node(x);
        ptr=ptr->next;
    }
    //Middle Element Removal
    Node *ptr1=head->next,*ptr2=head->next,*prev=NULL;
    while(ptr2->next!=NULL && ptr2->next->next!=NULL) {
        ptr2=ptr2->next->next;
        prev=ptr1;
        ptr1=ptr1->next;
    }
    prev->next=ptr1->next;
    //Display
    ptr=head->next;
    while(ptr!=NULL) {
        cout<<ptr->value<<endl;
        ptr=ptr->next;
    }
}