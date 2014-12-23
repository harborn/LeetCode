
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	int carry = 0;

	int val = l1->val + l2->val;
	ListNode *res = new ListNode(val % 10);
	carry = val / 10;
	
	ListNode *cur = res;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 && l2) {
		val = l1->val + l2->val + carry;
		cur->next = new ListNode(val % 10);
		carry = val / 10;
		cur = cur->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	
	while (l1) {
		val = l1->val + carry;
		cur->next = new ListNode(val % 10);
		carry = val / 10;
		cur = cur->next;
		l1 = l1->next;
	}
	while (l2) {
		val = l2->val + carry;
		cur->next = new ListNode(val % 10);
		carry = val / 10;
		cur = cur->next;
		l2 = l2->next;
	}
	if (carry) {
		cur->next = new ListNode(carry);
		cur = cur->next;
	}
	return res;
}

























ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
	ListNode* result = new ListNode(-1);
	ListNode* pre = result;
	ListNode *pa = l1, *pb = l2;
	int carry = 0;
	while (pa != NULL || pb != NULL)
	{
		int av = pa == NULL ? 0 : pa->val;
		int bv = pb == NULL ? 0 : pb->val;
		ListNode* node = new ListNode((av + bv + carry) % 10);
		carry = (av + bv + carry) / 10;
		pre->next = node;
		pre = pre->next;
		pa = pa == NULL ? NULL : pa->next;
		pb = pb == NULL ? NULL : pb->next;
	}
	if (carry >0)
		pre->next = new ListNode(1);
	pre = result->next;
	delete result;
	return pre;
}


int main(void)
{
	ListNode *l1, *l2;

	ListNode n11(2), n12(4), n13(3);
	ListNode n21(5), n22(6), n23(4);

	n11.next = &n12; n12.next = &n13;
	n21.next = &n22; n22.next = &n23;

	l1 = &n11;
	l2 = &n21;


	ListNode *res = addTwoNumbers(l1, l2);



	return 0;
}
