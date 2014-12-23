
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> helper(TreeNode *root) {
	vector<vector<int>> res;
	if (root == NULL) return res;

	vector<vector<int>> l = helper(root->left);
	vector<vector<int>> r = helper(root->right);

	
	if (l.empty() && r.empty()) {
		vector<int> path(1, root->val);
		res.push_back(path);
	}

	for (int i = 0; i < l.size(); i++) {
		vector<int> path(1, root->val);
		path.insert(path.end(), l[i].begin(), l[i].end());
		res.push_back(path);
	}

	for (int i = 0; i < r.size(); i++) {
		vector<int> path(1, root->val);
		path.insert(path.end(), r[i].begin(), r[i].end());
		res.push_back(path);
	}

	return res;
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int>> paths = helper(root);

	vector<vector<int>> res;

	for (int i = 0; i < paths.size(); i++) {
		int s = 0;
		for (int j = 0; j < paths[i].size(); j++) {
			s += paths[i][j];
		}
		if (s == sum) {
			res.push_back(paths[i]);
		}
	}

	return res;
}

int main(void)
{
	TreeNode *tree;
	TreeNode n1(5), n2(4), n3(8), n4(11), n6(13), n7(4), n8(7), n9(2), n14(5), n15(1);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4;
	n3.left = &n6; n3.right = &n7;
	n4.left = &n8; n4.right = &n9;
	n7.left = &n14; n7.right = &n15;

	tree = &n1;

	vector<vector<int>> res = pathSum(tree, 22);

	return 0;
}