#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *helper(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie) {
	if (ps > pe || is > ie) return NULL;
	TreeNode *node;
	node = new TreeNode(preorder[ps]);

	if (ps == pe && is == ie)
		return node;

	int pos = is;
	while (pos <= ie && inorder[pos] != preorder[ps]) pos++;

	int ll = pos - is;
	node->left = helper(preorder, ps + 1, ps + ll, inorder, is, pos - 1);
	node->right = helper(preorder, ps + ll + 1, pe, inorder, pos + 1, ie);

	return node;
}

TreeNode *buildTree3(vector<int> &preorder, vector<int> &inorder) {
	int ps = preorder.size(), is = preorder.size();
	if (!ps || !is) return NULL;
	return helper(preorder, 0, ps - 1, inorder, 0, is - 1);
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	int size = preorder.size();
	if (size == 0) return NULL;
	TreeNode *node;
	node = new TreeNode(preorder[0]);

	int pos = 0;
	while (inorder[pos] != preorder[0]) pos++;

	if (pos > 0) {
		vector<int> subLeftIn, subRightIn;
		for (int i = 0; i < pos; i++) subLeftIn.push_back(inorder[i]);
		for (int i = pos + 1; i < size; i++) subRightIn.push_back(inorder[i]);
		
		vector<int> subLeftPre, subRightPre;
		for (int i = 1; i < pos + 1; i++) subLeftPre.push_back(preorder[i]);
		for (int i = pos + 1; i < size; i++) subRightPre.push_back(preorder[i]);

		for (int i = 0; i < subLeftPre.size(); i++) {
			int v = subLeftPre[i];
			int f = 0;
			for (int j = 0; j < subLeftIn.size(); j++) {
				if (subLeftIn[j] == v) {
					f = 1; break;
				}
			}
			if (!f) return NULL;
		}

		node->left = buildTree(subLeftPre, subLeftIn);
		node->right = buildTree(subRightPre, subRightIn);
	}
	else {
		vector<int> subRightPre;
		vector<int> subRightIn;
		for (int i = 1; i < size; i++) {
			subRightPre.push_back(preorder[i]);
			subRightIn.push_back(inorder[i]);
		}
		node->right = buildTree(subRightPre, subRightIn);
	}

	return node;
}

TreeNode *buildTreeRecursion(vector<int> &preorder, int preS, int preE, vector<int> &inorder, int inS, int inE)
{
	if (preS > preE || inS > inE)
		return NULL;

	TreeNode* root = new TreeNode(preorder[preS]);

	if (preS == preE && inS == inE)
		return root;

	int inRoot;
	for (int i = inS; i <= inE; i++)
	{
		if (inorder[i] == preorder[preS])
		{
			inRoot = i;
		}
	}

	int numInLeft = inRoot - inS;
	root->left = buildTreeRecursion(preorder, preS + 1, preS + numInLeft, inorder, inS, inRoot - 1);
	root->right = buildTreeRecursion(preorder, preS + numInLeft + 1, preE, inorder, inRoot + 1, inE);

	return root;
}

TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) {
	if (!preorder.size() || !inorder.size())
		return NULL;

	TreeNode* root;
	root = buildTreeRecursion(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	return root;
}



int main(void)
{
	//int p[] = { 4, 2, 5, 1, 6, 3, 7 };
	//int p[] = { 1, 2, 4, 5, 3, 6, 7 };
	int p[] = { 1, 2, 3 };
	//int p[] = { 2, 3, 1 };
	//int p[] = { 1, 2 };
	int pn = sizeof(p) / sizeof(int);

	int i[] = { 2, 3, 1 };
	//int i[] = { 1, 2, 3 };
	//int i[] = { 1, 2, 4, 5, 3, 6, 7 };
	//int i[] = { 4, 2, 5, 1, 6, 3, 7 };
	//int i[] = { 2, 1 };
	int in = sizeof(i) / sizeof(int);

	vector<int> preorder;
	vector<int> inorder;

	preorder.insert(preorder.end(), p, p + pn);
	inorder.insert(inorder.end(), i, i + in);

	TreeNode *res = buildTree3(preorder, inorder);


	return 0;
}