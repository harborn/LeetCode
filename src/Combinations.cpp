
#include <iostream>
#include <vector>

using namespace std;

void helper(int n, int k, vector<int> seq, vector<vector<int>> &res) {
	if (k > n) return;
	if (n <= 0 || k <= 0) return;

	if (seq.size() == 0) {
		for (int i = 1; i <= n; i++) {
			seq.push_back(i);
		}
	}
	int p = 0;
	while (p < seq.size() - k) {
		vector<int> sub = seq;
		sub.erase(sub.begin() + p);
		helper(n - 1, k - 1, sub, res);
		if (res.empty()) {
			res.push_back(vector<int>(1, seq[p]));
		}
		else {
			for (int i = 0; i < res.size(); i++) {
				res[i].insert(res[i].begin(), seq[p]);
			}
		}
		
		p++;
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> seq;
	helper(n, k, seq, res);
	return res;
}

void GetCombine(
	int n,
	int k,
	int level,
	vector<int>& solution,
	vector<vector<int> >& result)
{
	if (solution.size() == k)
	{
		result.push_back(solution);
		return;
	}
	for (int i = level; i <= n; i++)
	{
		solution.push_back(i);
		GetCombine(n, k, i + 1, solution, result);
		solution.pop_back();
	}
}

vector<vector<int> > combine2(int n, int k) {
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function  
	vector<vector<int> > result;
	vector<int> solution;
	GetCombine(n, k, 1, solution, result);
	return result;
}

vector<vector<int> > combine3(int n, int k) {
	vector<vector<int> > result;
	if (k > n || n <= 0 || k <= 0)
		return result;
	vector<int> index(k);
	for (int i = 0; i < k; ++i)
	{
		index[i] = i + 1;
	}
	do
	{
		result.push_back(index);
		bool carry = false;
		int cur = k - 1;
		do {
			if (index[cur] < n - (k - 1 - cur))
			{
				carry = false;
				++index[cur];
				for (int i = 1; i + cur < k; ++i)
					index[i + cur] = index[cur] + i;
			}
			else
			{
				carry = true;
				if (--cur < 0)
					return result;
			}
		} while (carry && cur >= 0);
	} while (true);
	return result;
}

vector<vector<int> > combine4(int n, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > ret;
	if (n < k || k < 1) return ret;
	vector<int> numbers(k, 1);
	bool forward = true;
	int icur = 0;
	while (icur >= 0) {
		if (forward) {
			if (icur == k - 1) {
				ret.push_back(numbers);
				forward = false;
			}
			else {
				if (numbers[icur] < n) {
					numbers[icur + 1] = numbers[icur] + 1;
					++icur;
				}
				else {
					forward = false;
				}
			}
		}
		else {
			if (numbers[icur] < n) {
				++numbers[icur];
				forward = true;
			}
			else {
				--icur;
			}
		}
	}
	return ret;
}

int main(void)
{


	//vector<vector<int>> res = combine(4, 2);
	//vector<vector<int>> res = combine2(100, 3);
	vector<vector<int>> res = combine4(100, 3);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ", ";
		}
		cout << endl;
	}

	return 0;
}