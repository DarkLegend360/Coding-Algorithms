#include <bits/stdc++.h>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;
  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *getMiddleNode(LinkedList *head) {
	LinkedList *slow = head;
	LinkedList *fast = head;
	while(fast!=NULL && fast->next!=NULL) {
		slow=slow->next;
		fast =fast->next->next;
	}
	return slow;
}

LinkedList *reverseSecondHalf(LinkedList *head) {
	LinkedList *prev=NULL,*next;
	while(head!=NULL) {
		next = head->next;
		head->next  = prev;
		prev = head;
		head=next;
	}
	return prev;
}

bool isPalindrome(LinkedList *head,LinkedList *head2) {
	while(head2!=NULL && head!=NULL) {
		if(head->value!=head2->value)
			return false;
		head=head->next;
		head2=head2->next;
	}
	return true;
}

bool linkedListPalindrome(LinkedList *head) {
  LinkedList *middle = getMiddleNode(head);
	LinkedList *lastNode = reverseSecondHalf(middle);
	return isPalindrome(head,lastNode);
}

int main() {
    vector<int> inputs = {0,0,1,1,2,1,1,0,0};
    LinkedList *head=new LinkedList(-1);
    LinkedList *ptr=head;
    for(int x:inputs) {
        ptr->next=new LinkedList(x);
        ptr=ptr->next;
    }
    if(linkedListPalindrome(head->next))
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
    return 0;
}