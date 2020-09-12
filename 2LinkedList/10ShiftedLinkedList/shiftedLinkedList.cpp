#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int value;
        Node *next;
        Node(int value) {
            this->value = value;
            next=NULL;
        }
};

Node *shiftLinkedList(Node *head, int k) {
    int length=1;
	Node *tail = head;
	while(tail->next) {
		length++;
		tail=tail->next;
	}
	int offset = (k>0)?length - (k % length) : (abs(k) % length);
	if(offset==0) return head;
	Node *newTail =head;
	for(int i=1;i<offset;i++)
		newTail=newTail->next;
	tail->next=head;
	head =newTail->next;
	newTail->next=NULL;
  return head;
}