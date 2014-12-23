
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode *reverseBetween(ListNode *head, int m, int n) {
	if (head == NULL) return NULL;
	if (m == n) return head;

	int cnt = n - m + 1;
	int i = 0;
	ListNode *node1 = head;
	while (i < m - 2) {
		node1 = node1->next;
		i++;
	}
	ListNode *node2;
	if (m > 1) { node2 = node1->next; i++; }
	else node2 = head; 
	vector<ListNode *> v;
	while (i < n && node2) {
		v.push_back(node2);
		node2 = node2->next;
		i++;
	}
	for (int j = v.size() - 1; j >= 1; j--) {
		v[j]->next = v[j - 1];
	}
	if (m > 1)
		node1->next = v.back();
	v[0]->next = node2;

	if (m > 1)
		return head;
	else
		return v.back();
}

int main(void)
{
	ListNode *list;
	ListNode n1(1), n2(2), n3(3), Zn4(4), n5(5);
	n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
	list = &n1;

	ListNode *res = reverseBetween(list, 2, 4);

	return 0;
}