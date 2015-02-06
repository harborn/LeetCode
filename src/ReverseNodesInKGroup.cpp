
#include <iostream>
#include <vector>

using namespace std;
// 
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// 
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// 
// You may not alter the values in the nodes, only nodes itself may be changed.
// 
// Only constant memory is allowed.
// 
// For example,
// Given this linked list: 1->2->3->4->5
// 
// For k = 2, you should return: 2->1->4->3->5
// 
// For k = 3, you should return: 3->2->1->4->5

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head, int k) {
	if (head == NULL || head->next == NULL) return head;
	vector<ListNode *> lnv;
	ListNode *node = head, *res = NULL, *c = NULL;

	while (node) {
		if (lnv.size() < k) {
			lnv.push_back(node);
		}
		node = node->next;
		if (lnv.size() == k) {
			if (res == NULL)
				res = lnv.back();
			if (c != NULL) 
				c->next = lnv.back();

			int i = k - 1;
			while (i > 0) {
				lnv[i]->next = lnv[i-1];
				i--;
			}
			c = lnv.front();
			lnv.clear();
		}
	}

	if (lnv.size() != 0) {
		if (res == NULL)
			return head;
		if (c != NULL)
			c->next = lnv.front();
	}
	else {
		c->next = NULL;
	}

	return res;
}

int main(void) {

	ListNode *list;
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
	n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5; n5.next = &n6;
	list = &n1;

	ListNode* res = reverseKGroup(list, 7);

	return 0;
}