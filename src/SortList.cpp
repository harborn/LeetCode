
#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *sh = head, *st = head, *next, *insert, *cur = head, *last;

		next = head->next;
		sh->next = NULL;
		while (next) {
			cur = next;
			next = next->next;

			insert = sh; last = NULL;
			while (insert != NULL && insert->val < cur->val) {
				last = insert;
				insert = insert->next;
			}
			if (last == NULL) { // head
				sh = cur; sh->next = insert;
			}
			else if (insert == NULL) { // tail
				last->next = cur; cur->next = NULL;
			}
			else { // middle
				last->next = cur; cur->next = insert;
			}
		}

		return sh;
	}

public:
	ListNode *insertionSortList(ListNode *head) {

		if (head == NULL || head->next == NULL)
			return head;

		ListNode *nh, *nc, *c, *cn;

		c = head->next; cn = c->next;
		nh = head;
		nh->next = NULL;

		while (c) {

			nc = nh;
			if (nc->val >= c->val) {
				c->next = nh;
				nh = c;
			}
			else {
				while (nc->next && nc->next->val < c->val)
					nc = nc->next;

				c->next = nc->next;
				nc->next = c;
			}
			c = cn;
			if (cn != NULL) cn = cn->next;
		}
		head = nh;
	}
};

ListNode *sortList(ListNode *head) {
	if (head == NULL)
		return NULL;

	ListNode *sh = head, *next, *insert, *cur = head, *last;

	next = head->next;
	sh->next = NULL;
	while (next) {
		cur = next;
		next = next->next;

		insert = sh; last = sh;
		while (insert != NULL && insert->val < cur->val) {
			last = insert;
			insert = insert->next;
		}
		if (insert == sh) { // head
			sh = cur; sh->next = insert;
		}
		else if (insert == NULL) { // tail
			last->next = cur; cur->next = NULL;
		}
		else { // middle
			last->next = cur; cur->next = insert;
		}
	}

	return sh;
}

ListNode* mergeList(ListNode *l1, ListNode *l2) {
	if (l1 == NULL && l2 == NULL) return NULL;
	ListNode *head, *n1, *n2, *c;
	if (l1 == NULL) return l2;
	else if (l2 == NULL) return l1;

	if (l2->val < l1->val) {
		head = l2; n1 = l1; n2 = l2->next; c = n2;
	}
	else {
		head = l1; n1 = l1->next; n2 = l2; c = n1;
	}

	while (n1 != NULL && n2 != NULL) {
		if (n2->val < n1->val) {
			c->next = n2; n2 = n2->next;
		}
		else {
			c->next = n1; n1 = n1->next;
		}
		c = c->next;
	}
	if (n1 != NULL) c->next = n1;
	if (n2 != NULL) c->next = n2;

	return head;
}

ListNode *sortList2(ListNode *head) {

	int interval = 2, len = INT_MAX;
	int len1 = 0, len2 = 0;
	ListNode *l1, *l2, *c = head, *nh = NULL, *it = NULL;

	while (1) {
		len1 = 0; len2 = 0;
		l1 = c; len1++; c = c->next;
		while (len1 < interval && c != NULL) {
			l1->next = c; c = c->next; len1++;
		}
		l1->next = NULL;
		l2 = c; len2++; c = c->next;
		while (len2 < interval && c != NULL) {
			l2->next = c; c = c->next; len2++;
		}
		l2->next = NULL;
		
		if (len2 != 0) {
			mergeList(l1, l2);
		}

		
	}


}

ListNode *sortList(ListNode *head) {
	// IMPORTANT: Please reset any member data you declared, as  
	// the same Solution instance will be reused for each test case.  
	if (!head)
		return NULL;
	int k = 0;
	ListNode *p = head;
	while (p)
	{
		k++;
		p = p->next;
	}
	if (k == 1)
		return head;
	int l = k / 2;    //计算结点个数，将链表分开。  
	p = head;
	ListNode *q = head, *t = NULL;
	for (int i = 0; i<l && q; i++)
	{
		if (i == l - 1)
			t = q;
		q = q->next;
	}
	if (t)
		t->next = NULL;//将链表分开。  
	p = sortList(p);//分别对两段排序  
	q = sortList(q);
	ListNode *hd = NULL, *pp = NULL;
	while (p&&q)//合并  
	{
		if (p->val <= q->val)
		{
			if (!hd)
				pp = hd = p;
			else
			{
				pp->next = p;
				pp = p;
			}
			p = p->next;
		}
		else
		{
			if (!hd)
				hd = pp = q;
			else
			{
				pp->next = q;
				pp = q;
			}
			q = q->next;
		}
	}
	if (p)
		pp->next = p;
	if (q)
		pp->next = q;
	return hd;
}

int main(void)
{
	Solution s;
	ListNode *l;
	ListNode n0(1), n1(2), n2(33), n3(-12), n4(-25), n5(-3), n6(-8), n7(9), n8(100), n9(11);

	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;

	l = &n0;

	//s.sortList(l);
	//s.insertionSortList(l);
	ListNode *res = sortList(l);

	return 0;
}