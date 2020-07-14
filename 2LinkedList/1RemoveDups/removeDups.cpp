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
    //Removing Duplicates
    unordered_set<int> s;
    Node *prev=NULL;
    ptr=head->next;
    while(ptr!=NULL) {
        if(s.find(ptr->value)!=s.end())
            prev->next=ptr->next;
        else {
            s.insert(ptr->value);
            prev=ptr;
        }
        ptr=ptr->next;
    }
    //Display
    ptr=head->next;
    while(ptr!=NULL) {
        cout<<ptr->value<<endl;
        ptr=ptr->next;
    }
    return 0;
}