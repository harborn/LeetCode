
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> helper(vector<int> &num, int start, int target) {
	vector<vector<int>> res;
	if (target <= 0) return res;
	int size = num.size();

	for (int i = start; i < size; i++) {
		vector<vector<int>> sub = helper(num, i + 1, target - num[i]);
		if (target == num[i]) {
			vector<int> ans;
			ans.push_back(target);
			res.push_back(ans);
		}
		else {
			for (int j = 0; j < sub.size(); j++) {
				sub[j].insert(sub[j].begin(), num[i]);
				res.push_back(sub[j]);
			}
		}
		while ((i < size - 1) && num[i] == num[i + 1]) i++;
	}

	return res;
}

//bool less_vectors(const vector<int> &a, const vector<int> &b) {
//	return a.size() < b.size();
//}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	std::sort(num.begin(), num.end());
	vector<vector<int>> res = helper(num, 0, target);
	//if (res.empty()) return res;

	//std::sort(res.begin(), res.end(), less_vectors);

	//int i = 0;
	//while (i < res.size() - 1) {
	//	if ((res[i][0] == res[i + 1][0]) && (res[i].size() == res[i + 1].size())) {
	//		int j = 1;
	//		int l = res[i].size();
	//		while (j < l && (res[i][j] == res[i + 1][j])) {
	//			j++;
	//		}
	//		if (j == l) {
	//			res.erase(res.begin() + i + 1);
	//			continue;
	//		}
	//	}
	//	i++;
	//}

	return res;
}

int main(void)
{
	//int num[] = { 2, 2, 3, 3, 6, 7 };
	//int num[] = { 2 };
	//int num[] = { 3, 1, 3, 5, 1, 1 };
	int num[] = { 10, 1, 2, 7, 6, 1, 5 };
	int n = sizeof(num) / sizeof(int);

	vector<int> v;
	v.insert(v.end(), num, num + n);

	vector<vector<int>> res = combinationSum2(v, 8);

	return 0;
}