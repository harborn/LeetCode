
#include <iostream>
#include <vector>

using namespace std;

//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//The robot can only move either down or right at any point in time. 
//The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//How many possible unique paths are there?

int uniquePaths(int m, int n) {
	if (m <= 0 || n <= 0) return 0;
	if (m == 1 || n == 1) return 1;
	vector<vector<int>> t(m, vector<int>(n, 1));

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			t[i][j] = t[i][j-1] + t[i-1][j];
		}
	}

	return t[m-1][n-1];
}

int main(void)
{
	int res = uniquePaths(10,10);

	return 0;
}