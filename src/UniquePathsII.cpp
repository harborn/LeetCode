
#include <iostream>
#include <vector>

using namespace std;

//Follow up for "Unique Paths":
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.

//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]
//The total number of unique paths is 2.
//m and n will be at most 100.

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size();
	if (m == 0)	return 0;
	int n = obstacleGrid[0].size();
	if (n == 0) return 0;
	
	vector<vector<int>> t(m, vector<int>(n, 0));
	int i = 0;
	while (i < m) {
		if (obstacleGrid[i][0] != 0)
			break;
		t[i][0] = 1;
		i++;
	}
	while (i < m) {
		t[i][0] = 0;
		i++;
	}
	int j = 1;
	if (obstacleGrid[0][0] == 0) {
		while (j < n) {
			if (obstacleGrid[0][j] != 0)
				break;
			t[0][j] = 1;
			j++;
		}
	}
	while (j < n) {
		t[0][j] = 0;
		j++;
	}
	
	for (i = 1; i < m; i++) {
		for (j = 1; j < n; j++) {
			if (obstacleGrid[i][j] != 0)
				t[i][j] = 0;
			else 
				t[i][j] = t[i][j-1] + t[i-1][j];
		}
	}

	return t[m-1][n-1];
}

int main(void)
{
	vector<vector<int>> grid;
	vector<int> line;
	line.push_back(1);
	line.push_back(0);
	grid.push_back(line);

	int res = uniquePathsWithObstacles(grid);

	return 0;
}