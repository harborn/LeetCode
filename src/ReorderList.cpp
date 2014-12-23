
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// may could use size/2 memory.
void reorderList(ListNode *head) {
	vector<ListNode*> v;
	if (head == NULL) return;
	ListNode *node = head;
	while (node) {
		v.push_back(node);
		node = node->next;
	}

	int i = 0, j = v.size() - 1;
	while (i < j) {
		v[i]->next = v[j];
		v[j]->next = v[i + 1];
		i++; j--;
	}
	v[i]->next = NULL;
}

int main(void)
{
	ListNode *list;
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.next = &n2; n2.next = &n3; n3.next = &n4;// n4.next = &n5;
	list = &n1;

	reorderList(list);

	return 0;
}