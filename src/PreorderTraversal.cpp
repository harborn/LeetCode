#include <vector>
#include <iostream>
using namespace std;



//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preTra(TreeNode *root, vector<int> &order) {
	if (root == NULL) return;
	order.push_back(root->val);
	preTra(root->left, order);
	preTra(root->right, order);
}

vector<int> preorderTraversal(TreeNode *root) {
	vector<int> ret;
	preTra(root, ret);
	return ret;
}


int main(void)
{
	TreeNode *tree = NULL;

	vector<int> values = preorderTraversal(tree);

	return 0;
}