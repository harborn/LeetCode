
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root) {

}

void LevelTravel(TreeNode* node, int level, bool& hasNextLevel, vector<int>& result)
{
	if (!node) return;
	if (level == 1)
	{
		result.push_back(node->val);
		if (node->left || node->right)
			hasNextLevel = true;
		return;
	}
	else
	{
		LevelTravel(node->left, level - 1, hasNextLevel, result);
		LevelTravel(node->right, level - 1, hasNextLevel, result);
	}
}

vector<vector<int>> levelOrder(TreeNode *root) {
	vector<vector<int> > output;
	if (!root) return output;
	vector<int> oneLine;
	bool hasNextLevel = true;
	int currentLevel = 1;
	while (hasNextLevel)
	{
		hasNextLevel = false;
		LevelTravel(root, currentLevel, hasNextLevel, oneLine);
		output.push_back(oneLine);
		currentLevel++;
		oneLine.clear();
	}
	return output;
}

vector<vector<int> > levelOrder2(TreeNode *root) {
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function  
	vector<vector<int> > result;
	vector<TreeNode*> sta;
	if (root == NULL) return result;
	sta.push_back(root);
	int nextLevCou = 1;
	int index = 0;
	while (index < sta.size())
	{
		int curLevCou = nextLevCou;
		nextLevCou = 0;
		vector<int> level;
		for (int i = index; i< index + curLevCou; i++)
		{
			root = sta[i];
			level.push_back(root->val);
			if (root->left != NULL)
			{
				sta.push_back(root->left);
				nextLevCou++;
			}
			if (root->right != NULL)
			{
				sta.push_back(root->right);
				nextLevCou++;
			}
		}
		result.push_back(level);
		index = index + curLevCou;
	}
	return result;
}

int main(void)
{



	return 0;
}

