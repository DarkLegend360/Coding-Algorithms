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
    // vector<int> inputs = {1,2,3,4,5,5,4,3,2,1};
    vector<int> inputs = {0,0};
    Node *head=new Node(-1);
    Node *ptr=head;
    for(int x:inputs) {
        ptr->next=new Node(x);
        ptr=ptr->next;
    }
    //Finding Middle Node
    ptr=head->next;
    Node *ptr2 = head->next;
    Node *prev = NULL;
    while(ptr2->next!=NULL && ptr2->next->next!=NULL) {
        prev=ptr;
        ptr=ptr->next;
        ptr2=ptr2->next->next;
    }
    //Reversing Second Half
    prev=NULL;
    while(ptr!=NULL) {
        Node *next = ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
    }
    ptr2=prev;
    ptr=head->next;
    //Check Match
    while(ptr!=NULL && ptr2!=NULL) {
        cout<<ptr->value<<" x "<<ptr2->value<<endl;
        if(ptr->value!=ptr2->value) {
            cout<<"Invalid"<<endl;
            return 0;
        }
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    cout<<"Valid"<<endl;
    return 0;
}