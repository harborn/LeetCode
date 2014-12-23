
#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
	if (head == NULL) return NULL;
	ListNode *lh = NULL, *l = NULL, *gh = NULL, *g = NULL;

	while (head) {
		if (head->val < x) {
			if (lh == NULL) {
				lh = head; l = head;
			}
			else {
				l->next = head; l = head;
			}
		}
		else {
			if (gh == NULL) {
				gh = head; g = head;
			}
			else {
				g->next = head; g = head;
			}
		}
		head = head->next;
	}

	if (l) { l->next = gh; head = lh; }
	else { head = gh; }
	if (g) g->next = NULL;
	return head;
}

int main(void)
{
	ListNode *l;
	ListNode n1(2), n2(1);
	
	n1.next = &n2;

	l = &n1;

	l = partition(l, 1);


	return 0;
}