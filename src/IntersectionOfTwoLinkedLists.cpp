
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL) return NULL;
	ListNode *la = headA, *lb = headB;
	int lena = 1, lenb = 1;
	while (la->next) { la = la->next; lena++; }
	while (lb->next) { lb = lb->next; lenb++; }
	if (la != lb) return NULL;

	la = headA;
	lb = headB;
	while (lena > lenb) {la = la->next; lena--;}
	while (lenb > lena) {lb = lb->next; lenb--;}
	while (la != lb) {la = la->next; lb = lb->next;}

	return la;
}

int main(void) {

	ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);
	n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
	n6.next = &n7; n7.next = &n8; n8.next = &n3;

	ListNode *headA = &n1, *headB = &n6;

	ListNode *res = getIntersectionNode(headA, headB);
	

	return 0;
}