
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxPath(TreeNode *root, int &partVal) {
	if (root == NULL) return 0;
	int l = maxPath(root->left, partVal);
	int r = maxPath(root->right, partVal);
	
	int part = root->val;
	if (l > 0)
		part += l;
	if (r > 0)
		part += r;

	partVal = std::max(partVal, part);
	return std::max(root->val, std::max(root->val + l, root->val + r));
}



int maxPathSum(TreeNode *root) {
	int partVal = INT_MIN;
	int ret = maxPath(root, partVal);
	return std::max(ret, partVal);
}



int GetMax(TreeNode *node, int& maxAcrossRoot)
{
	if (node == NULL) return 0;
	int left = GetMax(node->left, maxAcrossRoot);
	int right = GetMax(node->right, maxAcrossRoot);
	int cMax = node->val;
	if (left>0)
		cMax += left;
	if (right>0)
		cMax += right;
	maxAcrossRoot = std::max(maxAcrossRoot, cMax);
	return std::max(
		node->val,
		std::max(node->val + left, node->val + right));
}

int maxPathSum2(TreeNode *root) {
	int maxAcrossRoot = INT_MIN;
	int maxEndByRoot = GetMax(root, maxAcrossRoot);
	return std::max(maxAcrossRoot, maxEndByRoot);
}



int main(void) {

	TreeNode *tree;
	TreeNode n1(-1), n2(-1), n3(-1), n4(-1), n5(-1), n6(-1), n7(-1), n8(4),
		n9(-1), n10(-1), n11(-1), n12(-1), n13(-1), n14(-1), n15(-1);

	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = &n5;
	n3.left = &n6; n3.right = &n7;
	n4.left = &n8; n4.right = &n9;
	n5.left = &n10; n5.right = &n11;
	n6.left = &n12; n6.right = &n13;
	n7.left = &n14; n7.right = &n15;

	tree = &n1;

	int res = maxPathSum(tree);

	return 0;
}