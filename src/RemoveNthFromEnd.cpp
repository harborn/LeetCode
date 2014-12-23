#include <iostream>



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
	if (n <= 0) return head;
	ListNode *runner = head, *start = head;
	while (n && runner) {
		n--;
		runner = runner->next;
	}
	if (n) return head;
	if (n == 0 && runner == NULL) return head->next;
	while (runner->next) {
		start = start->next;
		runner = runner->next;
	}
	start->next = start->next->next;

	return head;
}

int main(void)
{
	ListNode *l;
	ListNode n1(1), n2(2);
	n1.next = &n2;
	l = &n1;


	l = removeNthFromEnd(l, 1);

	return 0;
}