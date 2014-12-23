
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector<vector<int>> res;
	if (target <= 0) return res;
	int size = candidates.size();
	
	for (int i = 0; i < size; i++) {
		vector<vector<int>> sub = combinationSum(candidates, target - candidates[i]);
		if (target == candidates[i]) {
			vector<int> ans;
			ans.push_back(target);
			res.push_back(ans);
		}
		else {
			for (int j = 0; j < sub.size(); j++) {
				sub[j].insert(sub[j].begin(), candidates[i]);
				res.push_back(sub[j]);
			}
		}
	}

	return res;
}


void GetCombinations(
	vector<int>& candidates,
	int& sum,
	int level,
	int target,
	vector<int>& solution,
	vector<vector<int> >& result)
{
	if (sum > target) return;
	if (sum == target)
	{
		result.push_back(solution);
		return;
	}
	for (int i = level; i< candidates.size(); i++)
	{
		sum += candidates[i];
		solution.push_back(candidates[i]);
		GetCombinations(candidates, sum, i, target, solution, result);
		solution.pop_back();
		sum -= candidates[i];
	}
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
	vector<vector<int> > result;
	vector<int> solution;
	int sum = 0;
	std::sort(candidates.begin(), candidates.end());
	GetCombinations(candidates, sum, 0, target, solution, result);
	return result;
}



int main(void)
{
	int num[] = { 2, 3, 6, 7 };
	//int num[] = { 1, 1, 1 };
	int n = sizeof(num) / sizeof(int);
	vector<int> candidates;
	candidates.insert(candidates.end(), num, num + n);

	vector<vector<int>> res = combinationSum(candidates, 7);
	vector<vector<int>> res2 = combinationSum2(candidates, 7);

	return 0;
}