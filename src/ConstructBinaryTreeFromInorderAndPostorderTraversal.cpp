
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *helper(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe) {
	if (is > ie && ps > pe) return NULL;

	int rv = postorder[pe];

	TreeNode *node = new TreeNode(rv);

	int pos = is;

	while (pos <= ie && inorder[pos] != rv) pos++;
	int ll = pos - is;

	node->left = helper(inorder, is, pos - 1, postorder, ps, ps + ll - 1);
	node->right = helper(inorder, pos + 1, ie, postorder, ps + ll, pe - 1);

	return node;
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	if (inorder.size() == 0 || postorder.size() == 0) return NULL;
	return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

int main(void)
{
	int in[] = { 8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15 };
	int post[] = { 8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1 };

	int il = sizeof(in) / sizeof(int);
	int pl = sizeof(post) / sizeof(int);

	vector<int> inorder;
	vector<int> postorder;

	inorder.insert(inorder.begin(), in, in + il);
	postorder.insert(postorder.begin(), post, post + pl);

	TreeNode *res = buildTree(inorder, postorder);

	return 0;
}