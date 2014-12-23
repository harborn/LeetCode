
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int minDepth(TreeNode *root) {
	int depth = 0;
	if (root == NULL) return depth;
	
	vector<TreeNode *> pre;
	pre.push_back(root);
	TreeNode *l, *r, *leaf = NULL;
	int w = pre.size();
	depth++;
	while (w) {
		vector<TreeNode *> cur;
		leaf = NULL;
		for (int i = 0; i < pre.size(); i++) {
			l = pre[i]->left;
			r = pre[i]->right;

			if (l) {
				cur.push_back(l); leaf = l;
			}
			if (r) {
				cur.push_back(r); leaf = r;
			}

			if (l == NULL && r == NULL) {
				return depth;
			}
		}
		
		w = cur.size(); 
		if (w) depth++;

		pre.clear();
		pre.insert(pre.end(), cur.begin(), cur.end());
	}

	return depth;
}


int main(void)
{
	TreeNode *root;
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
	//n1.left = &n2;
	//n1.right = &n3;
	//n2.left = &n4;
	//n2.right = &n5;

	n1.right = &n2;
	n2.right = &n3;
	n3.right = &n4;
	n4.right = &n5;

	root = &n1;

	int res = minDepth(root);

	return 0;
}

