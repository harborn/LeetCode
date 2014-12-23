
#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL) return NULL;
	unordered_map<RandomListNode *, RandomListNode *> nodeMap;
	RandomListNode *oldNode = head;
	while (oldNode) {
		RandomListNode *newNode;
		if (nodeMap.find(oldNode) == nodeMap.end()) {
			newNode = new RandomListNode(oldNode->label);
			nodeMap[oldNode] = newNode;
		}
		else {
			newNode = nodeMap[oldNode];
		}

		if (oldNode->next) {
			RandomListNode *n;
			if (nodeMap.find(oldNode->next) == nodeMap.end()) {
				n = new RandomListNode(oldNode->next->label);
				nodeMap[oldNode->next] = n;
			}
			else {
				n = nodeMap[oldNode->next];
			}
			newNode->next = n;
		}
		else {
			newNode->next = NULL;
		}

		if (oldNode->random) {
			RandomListNode *r;
			if (nodeMap.find(oldNode->random) == nodeMap.end()) {
				r = new RandomListNode(oldNode->random->label);
				nodeMap[oldNode->random] = r;
			}
			else {
				r = nodeMap[oldNode->random];
			}
			newNode->random = r;
		}
		else {
			newNode->random = NULL;
		}

		oldNode = oldNode->next;
	}

	return nodeMap[head];
}

int main(void)
{
	RandomListNode *head;

	RandomListNode n0(0), n1(1), n2(2), n3(3), n4(4);

	n0.next = &n1; n1.next = &n2; n2.next = &n3; n3.next = &n4;
	n0.random = &n2; n1.random = &n4; n3.random = &n2; n4.random = &n0;

	head = &n0;

	RandomListNode *res = copyRandomList(head);

	return 0;
}

