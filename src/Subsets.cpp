
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int> > subsets(vector<int> &S) {
	int size = S.size();
	int n = 1 << size;

	vector<vector<int>> res;

	std::sort(S.begin(), S.end());

	for (int i = 0; i < n; i++) {
		int t = i;
		vector<int> set;
		int j = 0;
		while (t) {
			if (t & 1) {
				set.push_back(S[j]);
			}
			t >>= 1;
			j++;
		}
		res.push_back(set);
	}

	return res;
}

void generateSub(vector<int> &s, int step, vector<vector<int>> &result, vector<int>& output)
{
	for (int i = step; i < s.size(); i++)
	{
		output.push_back(s[i]);
		result.push_back(output);
		if (i < s.size() - 1)
			generateSub(s, i + 1, result, output);
		output.pop_back();
	}
}


vector<vector<int> > subsets2(vector<int> &S) {
	vector<vector<int> > result;
	vector<int> output;
	if (S.size() == 0) return result;
	result.push_back(output);
	sort(S.begin(), S.end());
	generateSub(S, 0, result, output);
}

int main(void)
{
	vector<int> S;
	S.push_back(0);
	S.push_back(1);
	S.push_back(4);



	vector<vector<int>> res = subsets(S);


	return 0;
}