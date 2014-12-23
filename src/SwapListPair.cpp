
#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *swapPairs(ListNode *head) {
	if (head == NULL || head->next == NULL) return head;

	ListNode *p1, *p2, *last;
	p1 = head->next;
	last = head;
	last->next = p1->next;
	p1->next = head;
	head = p1;

	while (last->next && last->next->next) {
		p1 = last->next;
		p2 = p1->next;
		p1->next = p2->next;
		p2->next = p1;
		last->next = p2;
		last = p1;
	}

	return head;
}


int main(void)
{
	ListNode *l;
	ListNode n1(1), n2(2);
	n1.next = &n2;

	l = &n1;

	ListNode *res = swapPairs(&n1);

	return 0;
}