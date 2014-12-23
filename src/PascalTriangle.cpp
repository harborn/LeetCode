

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows) {

	vector<vector<int>> res(numRows);
	if (numRows <= 0) return res;
	res[0].push_back(1);
	for (int i = 1; i < numRows; i++) {
		for (int j = 0; j < i+1; j++) {
			if (j == 0) res[i].push_back(1);
			else if (j == i) res[i].push_back(1);
			else res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
		}
	}

	return res;
}

vector<int> getRow(int rowIndex) {
	int numRows = rowIndex;
	vector<int> res2;
	if (numRows <= 0) return res2;
	vector<vector<int>> res(numRows);
	res[0].push_back(1);
	for (int i = 1; i < numRows; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) res[i].push_back(1);
			else if (j == i) res[i].push_back(1);
			else res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
		}
	}
	
	return res[rowIndex];
}


int main(void)
{
	vector<vector<int>> res = generate(4);

	return 0;
}
