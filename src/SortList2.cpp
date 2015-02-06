
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *prev, *next;
	ListNode(int v): val(v), prev(NULL), next(NULL) {}
};

ListNode *sort(ListNode *head) {
	if (head == NULL) return NULL;
	ListNode *node, *next, *insert, *temp;
	node = head; 
	next = head->next;
	node->prev = NULL;
	node->next = NULL;
	while (next) {
		insert = node;
		temp = next->next;
		while (insert->next && insert->val < next->val) insert = insert->next;
		if (insert == node) { // head
			next->next = node;
			node->prev = next;
			next->prev = NULL;
			node = next;
		}
		else {
			if (insert->next == NULL) { // tail
				insert->next = next;
				next->prev = insert;
				next->next = NULL;
			}
			else {//middle
				insert->next->prev = next;
				next->next = insert->next;
				next->prev = insert;
				insert->next = next;
			}
		}
		next = temp;
	}
	
	return node;
}

int main(void) {
	ListNode n1(1), n2(2), n3(3), n4(4);
	//n4.next = &n3; n3.prev = &n4;
	//n3.next = &n2; n2.prev = &n3;
	//n2.next = &n1; n1.prev = &n2;

	n1.next = &n2; n2.prev = &n1;
	n2.next = &n3; n3.prev = &n2;
	n3.next = &n4; n4.prev = &n3;
	
	ListNode *head = &n1;
	
	ListNode *res = sort(head);
	
	return 0;
}

