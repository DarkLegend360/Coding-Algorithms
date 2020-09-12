#include <vector>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
        Node(int value) {
            this->value = value;
            next = NULL;
        }
};

Node *mergeLinkedLists(Node *headOne, Node *headTwo) {
  Node *ptr1=headOne,*ptr2=headTwo,*prev=NULL;
	while(ptr1 && ptr2) {
		if(ptr1->value > ptr2->value) {
			if(prev==NULL)
				headOne=ptr2;
			else
				prev->next=ptr2;
			prev=ptr2;
			ptr2=ptr2->next;
			prev->next=ptr1;
		} else{
			prev=ptr1;
			ptr1=ptr1->next;
		}
	}
	if(!ptr1)
		prev->next=ptr2;
  return headOne;
}

/*
RECURSIVE

Node *mergeLinkedList(Node *a,Node *b) {
    merge(a,b);
    return (a->value<b->value)?a:b;
}

void merge(Node *p1,Node *p2,Node *prev=NULL) {
    if(p1==NULL) {
        prev->next=p2;
        return;
    }
    if(p2==NULL)
        return;
    if(p1->value>p2->value) {
        if(prev!=NULL)
            prev->next=p2;
        Node *next = p2->next;
        p2->next=p1;
        merge(p1,next,p2);
    } else 
        merge(p1->next,p2,p1);
}
*/

int main() {
    
    return 0;
}
