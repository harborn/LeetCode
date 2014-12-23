#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {

	int m = matrix.size();
	if (m == 0) return false;
	int n = matrix[0].size();
	if (n == 0) return false;

	int c = 0, r = 0;
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (matrix[i][j] > target) {
			break;
		}
		else if (matrix[i][j] == target) {
			return true;
		}
		i++; j++;
	}

	if (i == m && j == n)
		return false;
	
	r = i - 1; c = j - 1;
	for (int i = r; i < m; i++) {
		for (int j = 0; j <= c; j++) {
			if (matrix[i][j] == target)
				return true;
		}
	}

	for (int i = 0; i <= r; i++) {
		for (int j = c; j < n; j++) {
			if (matrix[i][j] == target)
				return true;
		}
	}

	return false;
}

int main(void)
{


	return 0;
}