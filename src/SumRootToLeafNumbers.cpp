
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

vector<string> helper(TreeNode *root) {
	vector<string> res;
	if (root == NULL) return res;

	vector<string> l = helper(root->left);
	vector<string> r = helper(root->right);

	if (l.empty() && r.empty())
		res.push_back(std::to_string(root->val));

	for (int i = 0; i < l.size(); i++) {
		string s = std::to_string(root->val);
		res.push_back(s.append(l[i]));
	}

	for (int i = 0; i < r.size(); i++) {
		string s = std::to_string(root->val);
		res.push_back(s.append(r[i]));
	}

	return res;
}

int stringAdd(string s1, string s2) {
	int res = 0;
	int size1 = s1.size();
	int size2 = s2.size();
	int carry = 0;
	int i = 0, j = 0;
	while (i < size1 && j < size2) {
		int n = s1[i] - '0' + s2[j] - '0' + carry;
		res = res * 10 + n % 10;
		carry = n / 10;
		i++; j++;
	}
	while (i < size1) {
		int n = s1[i] - '0' + carry;
		res = res * 10 + n % 10;
		carry = n / 10;
		i++;
	}
	while (j < size2) {
		int n = s2[i] - '0' + carry;
		res = res * 10 + n % 10;
		carry = n / 10;
		j++;
	}




	return res;
}

int sumNumbers(TreeNode *root) {
	vector<string> res =  helper(root);

	int sum = 0;
	for (int i = 0; i < res.size(); i++) {
		sum += stoi(res[i]);
	}

	return sum;
}



int main(void)
{
	int n = atoi("32");
	//int n = stringAdd("12", "3");


	TreeNode *tree;
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n12(12);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4;
	n3.left = &n6;
	n6.left = &n12;
	n3.right = &n7;
	n4.left = &n8;

	tree = &n1;

	vector<string> res = helper(tree);


	int sum = sumNumbers(tree);
	return 0;
}