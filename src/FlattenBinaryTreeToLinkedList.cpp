#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode *root, vector<TreeNode *> &val)
{
	if (root == NULL) return;
	val.push_back(root);
	helper(root->left, val);
	helper(root->right, val);
}

void flatten(TreeNode *root) {
	if (root == NULL) return;
	vector<TreeNode *> val;
	helper(root, val);
	for (int i = 0; i < val.size() - 1; i++) {
		val[i]->right = val[i + 1];
		val[i]->left = NULL;
	}
	val.back()->right = NULL;
	val.back()->left = NULL;
}

void flatten2(TreeNode *root) {
	while (root) {
		if (root->left) {
			TreeNode *left = root->left;
			while (left->right) left = left->right;
			left->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		root = root->right;
	}
}

int main(void)
{
	TreeNode *tree;
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
	n1.left = &n2; n1.right = &n5;
	n2.left = &n3; n2.right = &n4;
	n5.right = &n6;

	tree = &n1;
	
	flatten(tree);

	return 0;
}