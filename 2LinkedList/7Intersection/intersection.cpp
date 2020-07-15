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

Node *createList(vector<int> inputs) {
    Node *head=new Node(-1);
    Node *ptr=head;
    for(int x:inputs) {
        ptr->next=new Node(x);
        ptr=ptr->next;
    }
    return head->next;
}

int main() {
    Node *linkA = createList({1,2,3,4});
    Node *linkB = createList({1,2});
    Node *linkC = createList({7,8,9});
    Node *ptr=linkA,*ptr2;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=linkC;
    ptr=linkB;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=linkC;
    //Intersection Code
    ptr=linkA;
    ptr2=linkB;
    while(ptr!=ptr2) {
        ptr=ptr->next;
        ptr2=ptr2->next;
        if(ptr==ptr2) {
            if(ptr==NULL)
                cout<<"No Intersection"<<endl;
            else
                cout<<"Result:"<<ptr->value<<endl;
            return 0;
        }
        if(ptr==NULL)
            ptr=linkB;
        if(ptr2==NULL)
            ptr2=linkA;
    }
}