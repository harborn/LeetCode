
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {

	int size = lists.size();
	
	if (size == 0) return NULL;
	else if (size == 1) return lists[0];
	
	ListNode *res = NULL;
	ListNode *node = NULL; int i = 0, m = 0;
	while (i < size && !(node = lists[i])) i++;
	if (node == NULL) return res;
	m = i;
	while (i < size) {
		if (lists[i] != NULL && lists[i]->val < node->val) {
			node = lists[i]; m = i;
		}
		i++;
	}
	lists[m] = lists[m]->next;
	res = node;

	while (node != NULL) {
		i = 0;
		ListNode *node2 = NULL;
		while (i < size && !(node2 = lists[i])) i++;
		m = i;
		while (i < size) {
			if (lists[i] != NULL && lists[i]->val < node2->val) {
				node2 = lists[i]; m = i;
			}
			i++;
		}
		if (m < size)
			lists[m] = lists[m]->next;
		node->next = node2;
		node = node2;
	}
	return res;
}

int main(void)
{
	ListNode b(0);
	ListNode *a1 = &b;
	ListNode *c1 = NULL;
	a1 = c1;

	ListNode *l1;
	ListNode *l2;
	ListNode n21(1);

	l1 = NULL;
	l2 = &n21;

	vector<ListNode *> ls;

	ls.push_back(l1);
	ls.push_back(l2);

	ListNode *res;

	res = mergeKLists(ls);

	return 0;
}


