
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int> &num) {
	vector<vector<int>> res;
	int size = num.size();
	if (size == 0) return res;
	
	for (int i = 0; i < size; i++) {
		vector<int> sub = num;
		sub.erase(sub.begin()+i);
		vector<vector<int>> sr = permute(sub);
		if (sr.empty()) {
			res.push_back(vector<int>(1, num[i]));
		} else {
			for (int j = 0; j < sr.size(); j++) {
				sr[j].insert(sr[j].begin(), num[i]);
				res.push_back(sr[j]);
			}
		}
	}

	return res;
}

int main(void)
{
	int A[] = {1,2,3,4};
	int n = sizeof(A) / sizeof(int);
	vector<int> num;
	num.insert(num.begin(), A, A+n);

	vector<vector<int>> res = permute(num);

	return 0;
}