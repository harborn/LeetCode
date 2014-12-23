
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode *root, vector<TreeNode *> &inorder) {
	if (root == NULL) return;
	helper(root->left, inorder);
	inorder.push_back(root);
	helper(root->right, inorder);
}

void recoverTree(TreeNode *root) {
	vector<TreeNode *> inorder;
	helper(root, inorder);
	int i = 0, j = inorder.size()-1;
	int p1 = -1, p2 = -1;
	while (i+1 < inorder.size() && inorder[i]->val < inorder[i+1]->val) i++;
	p1 = i;
	while (j-1 >= 0 && inorder[j]->val > inorder[j-1]->val) j--;
	p2 = j;
	int v = inorder[p1]->val;
	inorder[p1]->val = inorder[p2]->val;
	inorder[p2]->val = v;
}

int main(void)
{
	TreeNode *tree;
	TreeNode n1(1), n2(2), n3(3);
	n1.left = &n2;// n1.right = &n3;

	tree = &n1;

	recoverTree(tree);

	return 0;
}