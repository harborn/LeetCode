
#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid) {

	int row = grid.size();
	if (row == 0) return 0;
	int col = grid[0].size();
	if (col == 0) return 0;

	for (int i = 1; i < col; i++) {
		grid[0][i] += grid[0][i-1];
	}
	for (int j = 1; j < row; j++) {
		grid[j][0] += grid[j-1][0];
	}

	for (int j = 1; j < row; j++) {
		for (int i = 1; i < col; i++) {
			grid[j][i] += (grid[j-1][i] < grid[j][i-1]) ? grid[j-1][i] : grid[j][i-1];
		}
	}
	return grid[row-1][col-1];
}


int main(void)
{


	return 0;
}