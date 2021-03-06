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
    int K=2;
    Node *ptr1=head->next,*ptr2=head->next;
    int count=0;
    while(ptr1!=NULL) {
        if(count++>=K) {
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    cout<<"Result:"<<ptr2->value<<endl;
}