
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode *deleteDuplicates(ListNode *head) {
	if (head == NULL) return NULL;

	ListNode *h, *node, *last, *t;
	h = NULL;
	last = NULL;
	node = head;
	int cnt = 0;
	int v;
	while (node) {
		cnt = 0;
		v = node->val;
		t = node;
		while (node && node->val == v) {
			cnt += 1;
			node = node->next;
		}
		if (cnt == 1) {
			if (last == NULL) {
				h = t;
				last = t;
			}
			else {
				last->next = t;
				last = t;
			}
		}
	}
	if (last)
		last->next = NULL;

	return h;
}

int main(void)
{
	ListNode *list;
	ListNode n1(1), n2(1), n3(3), n4(3), n5(4), n6(4), n7(5);
	n1.next = &n2; 
	//n2.next = &n3; n3.next = &n4; n4.next = &n5; 
	//n5.next = &n6; n6.next = &n7;

	list = &n1;

	ListNode *res = deleteDuplicates(list);

	return 0;
}