
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == NULL) return NULL;
	queue<UndirectedGraphNode *> q;
	map<int, UndirectedGraphNode*> newGraph;
	UndirectedGraphNode *newNode;
	q.push(node);
	while (!q.empty()) {
		UndirectedGraphNode *old = q.front();
		if (newGraph.find(old->label) == newGraph.end()) {
			newNode = new UndirectedGraphNode(old->label);
			newGraph[old->label] = newNode;
		}
		else {
			newNode = newGraph[old->label];
		}
		q.pop();
		for (int i = 0; i < old->neighbors.size(); i++) {
			int l = old->neighbors[i]->label;
			UndirectedGraphNode *t = old->neighbors[i];
			if (newGraph.find(l) == newGraph.end()) {
				UndirectedGraphNode *t2 = new UndirectedGraphNode(l);
				newGraph[l] = t2;
				q.push(t);
				newNode->neighbors.push_back(t2);
			}
			else {
				newNode->neighbors.push_back(newGraph[l]);
			}
		}
	}

	return newGraph[node->label];
}

void helper(UndirectedGraphNode *node, map<int, bool> &visited, map<int, UndirectedGraphNode *> &newGraph) {
	if (node == NULL) return;
	UndirectedGraphNode *newNode;
	if (newGraph.find(node->label) == newGraph.end()) {
		newNode = new UndirectedGraphNode(node->label);
		visited[node->label] = false;
		newGraph[node->label] = newNode;
	}
	else {
		newNode = newGraph[node->label];
	}

	if (!visited[node->label]) {
		for (int i = 0; i < node->neighbors.size(); i++) {
			int l = node->neighbors[i]->label;
			if (newGraph.find(l) == newGraph.end()) {
				UndirectedGraphNode *t = new UndirectedGraphNode(l);
				visited[l] = false;
				newGraph[l] = t;
				newNode->neighbors.push_back(t);
			}
			else {
				newNode->neighbors.push_back(newGraph[l]);
			}
			visited[node->label] = true;
			helper(node->neighbors[i], visited, newGraph);
		}
	}
}

UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {

	if (node == NULL) return NULL;

	map<int, bool> visited;
	map<int, UndirectedGraphNode *> newGraph;
	helper(node, visited, newGraph);

	return newGraph[node->label];
}


void cloneGraph_core(UndirectedGraphNode *node, UndirectedGraphNode* &res, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& originToCopy)
{
	if (originToCopy[node])
		res = originToCopy[node];
	else
	{
		res = new UndirectedGraphNode(node->label);
		originToCopy[node] = res;
	}

	int len = node->neighbors.size();
	if (res->neighbors.empty()) {
		for (int i = 0; i < len; i++)
		{
			res->neighbors.push_back(0);
			cloneGraph_core(node->neighbors[i], res->neighbors.back(), originToCopy);
		}
	}
}

UndirectedGraphNode *cloneGraph3(UndirectedGraphNode *node)
{
	if (!node) return 0;
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> originToCopy;

	UndirectedGraphNode *res;
	cloneGraph_core(node, res, originToCopy);
	return res;
}

int main(void)
{
	UndirectedGraphNode *graph;

	UndirectedGraphNode n0(0), n1(1), n2(2);
	n0.neighbors.push_back(&n1);
	n0.neighbors.push_back(&n2);
	n1.neighbors.push_back(&n0);
	n1.neighbors.push_back(&n2);
	n2.neighbors.push_back(&n0);
	n2.neighbors.push_back(&n1);
	n2.neighbors.push_back(&n2);
	graph = &n0;

	//UndirectedGraphNode n0(-1);
	//graph = &n0;

	UndirectedGraphNode *res = cloneGraph3(graph);

	return 0;
}