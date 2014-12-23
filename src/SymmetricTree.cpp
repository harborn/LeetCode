
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode *left, TreeNode *right)
{
	if (left == NULL && right == NULL) return true;
	if (left == NULL) return false;
	if (right == NULL) return false;

	if (left->val != right->val) return false;

	bool h1 = helper(left->left, right->right);
	bool h2 = helper(left->right, right->left);

	return h1 & h2;
}

// recusive solution
bool isSymmetric(TreeNode *root) {
	if (root == NULL) return true;
	return helper(root->left, root->right);
}

// not recusive solution
// using level traverse

int main(void)
{


	return 0;
}