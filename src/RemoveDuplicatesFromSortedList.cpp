#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) {
	if (head == NULL) return NULL;

	ListNode *node, *last;
	last = head;
	node = head->next;
	int v = head->val;
	while (node) {
		if (v != node->val) {
			last->next = node;
			last = node;
			v = node->val;
		}
		node = node->next;
	}
	last->next = NULL;

	return head;
}

int main(void)
{
	ListNode *list;
	ListNode n1(1), n2(1), n3(2), n4(3), n5(3);

	n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;

	list = &n1;

	ListNode *new_list = deleteDuplicates(list);

	return 0;
}