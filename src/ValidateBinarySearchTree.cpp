
#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode *root, int min, int max) {
	if (root == NULL) return true;
	TreeNode *left = root->left, *right = root->right;

	if ((root->val > min) && helper(left, min, root->val) &&
		(root->val < max) && helper(right, root->val, max))
		return true;
	else
		return false;
}


bool isValidBST(TreeNode *root) {
	return helper(root, INT_MIN, INT_MAX);
}


int main(void)
{
	cout << SHRT_MIN << endl;
	cout << SHRT_MAX << endl;
	cout << INT_MAX << endl;
	cout << INT_MIN << endl;

	TreeNode *t;
	TreeNode n1(0);

	t = &n1;

	bool res = isValidBST(t);


	return 0;
}