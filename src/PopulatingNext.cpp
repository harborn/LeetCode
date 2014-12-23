

#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

vector<TreeLinkNode *> traverse(TreeLinkNode *node){
	vector<TreeLinkNode *> res;
	if (node == NULL) { return res; }
	vector<TreeLinkNode *> l = traverse(node->left);
	res.push_back(node);
	vector<TreeLinkNode *> r = traverse(node->right);
	l.insert(l.end(), res.begin(), res.end());
	l.insert(l.end(), r.begin(), r.end());

	return l;
}

void connect(TreeLinkNode *root) {
	if (root == NULL) return;

	connect(root->left);
	connect(root->right);

	vector<TreeLinkNode *> l = traverse(root->left);
	vector<TreeLinkNode *> r = traverse(root->right);
	while (!l.empty() && !r.empty()) {
		if (l.back()->next == NULL)
			l.back()->next = r.front();
		l.pop_back(); r.erase(r.begin());
	}
	root->next = NULL;
}



vector<TreeLinkNode *> traverse2(TreeLinkNode *root) {
	vector<TreeLinkNode *> res;
	if (root == NULL) return res;

	res.push_back(root);
	
	TreeLinkNode *node = root->left;
	int w = 1; int p = 0;
	while (node) {
		for (int i = 0; i < w; i++) {
			res.push_back(res[p + i]->left);
			res.push_back(res[p + i]->right);
		}
		p += w;
		node = res[p]->left;
		w <<= 1;
	}

	return res;
}

void connect2(TreeLinkNode *root) {
	if (root == NULL) return;

	vector<TreeLinkNode*> res = traverse2(root);
	
	int w = 1; int p = 0;
	int l = res.size() - 1;
	while (p < l) {
		int i = 0;
		while (i < w - 1) {
			res[p + i]->next = res[p + i + 1];
			i++;
		}
		res[p + w - 1]->next = NULL;
		p += w;
		w <<= 1;
	}
}

vector<vector<TreeLinkNode *>> traverse3(TreeLinkNode *root) {
	vector<vector<TreeLinkNode *>> res;
	if (root == NULL) return res;

	vector<TreeLinkNode *> level;
	
	level.push_back(root);
	res.push_back(level);

	TreeLinkNode *node = root->left;
	TreeLinkNode *l, *r;
	int w = level.size();
	while (w) {
		vector<TreeLinkNode *> pre = res.back();
		vector<TreeLinkNode *> cur;
		for (int i = 0; i < pre.size(); i++) {
			l = pre[i]->left;
			r = pre[i]->right;
			if (l) cur.push_back(l);
			if (r) cur.push_back(r);
		}
		w = cur.size();
		if (w) res.push_back(cur);
	}

	return res;
}


void connect3(TreeLinkNode *root) {
	if (root == NULL) return;

	vector<vector<TreeLinkNode *>> res = traverse3(root);
	int h = res.size();
	for (int i = 0; i < h; i++) {
		int w = res[i].size() - 1;
		for (int j = 0; j < w; j++) {
			res[i][j]->next = res[i][j + 1];
		}
		res[i][w]->next = NULL;
	}
}

int main(void)
{
	TreeLinkNode n1(1); TreeLinkNode n2(2);
	TreeLinkNode n3(3); TreeLinkNode n4(4);
	TreeLinkNode n5(5); TreeLinkNode n6(6);
	TreeLinkNode n7(7); TreeLinkNode n8(8);
	TreeLinkNode n9(9); TreeLinkNode n10(10);
	TreeLinkNode n11(11); TreeLinkNode n12(12);
	TreeLinkNode n13(13); TreeLinkNode n14(14);
	TreeLinkNode n15(15);

	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = &n5;
	n3.left = &n6; n3.right = &n7;
	n4.left = &n8; n4.right = &n9;
	n5.left = &n10; n5.right = &n11;
	n6.left = &n12; n6.right = &n13;
	n7.left = &n14; n7.right = &n15;
	
	//vector<TreeLinkNode*> res = traverse2(&n1);
	connect3(&n1);
	return 0;
}
