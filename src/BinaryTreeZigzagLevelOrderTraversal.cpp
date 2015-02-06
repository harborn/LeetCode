
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//  ->------>-
//  -<------<-
//  ->------>-
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
	vector<vector<int>> res;
	if (root == NULL) return res;

	stack<TreeNode *> st1, *pst1;
	stack<TreeNode *> st2, *pst2;

	st1.push(root);
	pst1 = &st1;
	pst2 = &st2;
	while (!pst1->empty()) {
		vector<int> v;
		while (!pst1->empty()) {
			TreeNode *tn = pst1->top();
			v.push_back(tn->val);
			if (pst2 == &st2) {
				if (tn->left)
					pst2->push(tn->left);
				if (tn->right)
					pst2->push(tn->right);
			} else {
				if (tn->right)
					pst2->push(tn->right);
				if (tn->left)
					pst2->push(tn->left);
			}
			pst1->pop();
		}
		res.push_back(v);
		if (pst1 == &st1) {
			pst1 = &st2;
			pst2 = &st1;
		} else {
			pst1 = &st1;
			pst2 = &st2;
		}
	}

	return res;
}

int main(void)
{
	TreeNode *tree;
	TreeNode n1(3), n2(9), n3(20), n4(15), n5(7);

	n1.left = &n2; n1.right = &n3;
	n3.left = &n4; n3.right = &n5;

	tree = &n1;

	vector<vector<int>> res = zigzagLevelOrder(tree);

	return 0;
}