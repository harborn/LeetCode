
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


static int cnt = 0;

void dfs(int st, int ed, vector<TreeNode *> &res) {
	if (st > ed) {
		res.push_back(NULL);
	}
	else {
		for (int i = st; i <= ed; i++) {
			vector<TreeNode *> lefts;
			dfs(st, i - 1, lefts);
			vector<TreeNode *> rights;
			dfs(i + 1, ed, rights);

			for (int li = 0; li < lefts.size(); li++) {
				for (int ri = 0; ri < rights.size(); ri++) {
					TreeNode* node = new TreeNode(i);
					cnt++;
					node->left = lefts[li];
					node->right = rights[ri];
					res.push_back(node);
				}
			}
		}
	}
}

vector<TreeNode *> generateTrees(int n) {
	vector<TreeNode*> res;
	dfs(1, n, res);
	return res;
}

int main(void)
{
	
	vector<TreeNode *> res = generateTrees(5);
	cout << cnt << endl;

	return 0;
}