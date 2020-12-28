#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *prev;
    Node *next;
    Node(int value);
};


class DoublyLinkedList {
    public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void setHead(Node *node) {
        if(head==NULL) {
            head=node;
            tail=node;
        } else
            insertBefore(head,node);
    }

    void setTail(Node *node) {
        if(tail==NULL)
            setHead(node);
        else
            insertAfter(tail,node);
    }

    void insertBefore(Node *node, Node *nodeToInsert) {
        remove(nodeToInsert);
        nodeToInsert->next=node;
        nodeToInsert->prev=node->prev;
        if(node->prev==NULL)
            head=nodeToInsert;
        else
            node->prev->next=nodeToInsert;
        node->prev=nodeToInsert;
    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        remove(nodeToInsert);
        nodeToInsert->prev=node;
        nodeToInsert->next=node->next;
        if(node->next==NULL)
            tail=nodeToInsert;
        else
            node->next->prev=nodeToInsert;
        node->next=nodeToInsert;
    }

    void insertAtPosition(int position, Node *nodeToInsert) {
        if(position==1) {
            setHead(nodeToInsert);
            return;
        }
        Node *cur=head;
        int curPos=1;
        while(cur && curPos++!=position)
            cur=cur->next;
        if(!cur)
            setTail(nodeToInsert);
        else
            insertBefore(cur,nodeToInsert);
    }

    void removeNodesWithValue(int value) {
        Node *cur = head;
        while(cur) {
            Node *nodeToRemove = cur;
            cur=cur->next;
            if(nodeToRemove->value==value)
                remove(nodeToRemove);
        }
    }

    void remove(Node *node) {
        if(head==node)
            head=head->next;
        if(tail==node)
            tail=tail->prev;
        if(node->prev)
            node->prev->next=node->next;
        if(node->next)
            node->next->prev=node->prev;
        node->next=NULL;
        node->prev=NULL;
    }

    bool containsNodeWithValue(int value) {
        Node *cur = head;
        while(cur && cur->value!=value)
            cur=cur->next;
        return cur!=NULL;
    }
};
