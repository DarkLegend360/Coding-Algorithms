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

Node *createReverseList(int n) {
    string s=to_string(n);
    reverse(s.begin(),s.end());
    Node *head=new Node(-1);
    Node *ptr=head;
    for(auto x:s) {
        ptr->next=new Node(x-'0');
        ptr=ptr->next;
    }
    return head->next;
}

int getNumber(Node *ptr) {
    string res ="";
    while(ptr!=NULL) {
        res=to_string(ptr->value)+res;
        ptr=ptr->next;
    }
    return stoi(res);
}

int main() {
    Node *F1=createReverseList(617);
    Node *F2=createReverseList(295);
    int a = getNumber(F1);
    int b = getNumber(F2);
    Node *res = createReverseList(a+b);
    while (res!=NULL) {
        cout<<res->value<<" ";
        res=res->next;
    }
    cout<<endl;
}