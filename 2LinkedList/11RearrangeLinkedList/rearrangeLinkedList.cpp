#include <bits/stdc++.h>
using namespace std;

class LinkedList {
    public:
    int value;
    LinkedList *next;
    LinkedList(int value) {
        this->value = value;
        next = NULL;
    }
};

class LinkedListPair {
    public:
    LinkedList *head;
    LinkedList *tail;
};

LinkedListPair growLinkedList(LinkedList *head,LinkedList *tail,LinkedList *node) {
    LinkedList *newHead = head;
    LinkedList *newTail = node;
    if(!newHead)
        newHead = node;
    if(tail)
        tail->next=newTail;
    return LinkedListPair{newHead,newTail};
}

LinkedListPair connectLinkedList(LinkedList *headOne,LinkedList *tailOne,LinkedList *headTwo,LinkedList *tailTwo) {
    LinkedList *newHead=headOne?headOne:headTwo;
    LinkedList *newTail=tailTwo?tailTwo:tailOne;
    if(tailOne)
        tailOne->next=headTwo;
    return LinkedListPair{newHead,newTail   };
}

LinkedList *rearrangeLinkedList(LinkedList *head, int k) {
    LinkedList *smallerListHead=NULL;
	LinkedList *smallerListTail=NULL;
	LinkedList *equalListHead=NULL;
	LinkedList *equalListTail=NULL;
	LinkedList *greaterListHead=NULL;
	LinkedList *greaterListTail=NULL;
    while(head!=NULL) {
        if(head->value>k) {
            LinkedListPair greaterList = growLinkedList(greaterListHead,greaterListTail,head);
            greaterListHead=greaterList.head;
            greaterListTail=greaterList.tail; 
        }
        else if(head->value<k) {
            LinkedListPair smallerList = growLinkedList(smallerListHead,smallerListTail,head);
            smallerListHead = smallerList.head;
            smallerListTail = smallerList.tail;
        }
        else {
            LinkedListPair equalList = growLinkedList(equalListHead,equalListTail,head);
            equalListHead = equalList.head;
            equalListTail = equalList.tail;
        }
        LinkedList *prevNode = head;
        head=head->next;
        prevNode->next=NULL;
    }
    LinkedListPair firstList = connectLinkedList(smallerListHead,smallerListTail,equalListHead,equalListTail);
    LinkedList *firstListHead = firstList.head;
    LinkedList *firstListTail = firstList.tail;
    LinkedListPair finalList = connectLinkedList(firstListHead,firstListTail,greaterListHead,greaterListTail);
    LinkedList *finalListHead = finalList.head;
    LinkedList *finalListTail = finalList.tail;
    return finalListHead;
}

int main() {
    vector<int> inputs = {3,0,5,2,1,4};
    LinkedList *head=new LinkedList(-1);
    LinkedList *ptr=head;
    for(auto x:inputs) {
        ptr->next=new LinkedList(x);
        ptr=ptr->next;
    }
    int k=3;
    LinkedList *result = rearrangeLinkedList(head->next,k);
    while(result!=NULL) {
        cout<<result->value<<" ";
        result=result->next;
    }
    cout<<endl;
    return 0;
}