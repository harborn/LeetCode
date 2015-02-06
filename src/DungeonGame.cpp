
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateMinimumHP(vector<vector<int> > &dungeon) {
	int m = dungeon.size(), n = dungeon[0].size();
	vector<vector<int>> sum(m, vector<int>(n, 0));
	vector<vector<int>> dp(m, vector<int>(n, 0));
	sum[0][0] = dungeon[0][0]; dp[0][0] = dungeon[0][0];
	for (int i = 1; i < m; i++) {
		sum[i][0] = sum[i - 1][0] + dungeon[i][0];
		dp[i][0] = min(sum[i][0], dp[i - 1][0]);
	}
	for (int j = 1; j < n; j++) {
		sum[0][j] = sum[0][j - 1] + dungeon[0][j];
		dp[0][j] = min(sum[0][j], dp[0][j - 1]);
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			int leftPath = sum[i][j - 1] + dungeon[i][j];
			int upPath = sum[i - 1][j] + dungeon[i][j];
			int minLeft = min(dp[i][j - 1], leftPath);
			int minUp = min(dp[i - 1][j], upPath);
			sum[i][j] = max(leftPath, upPath);
			dp[i][j] = max(minLeft, minUp);
		}
	}
	if (dp[m - 1][n - 1] > 0) return 1;
	return 1 - dp[m - 1][n - 1];
}

int calculateMinimumHP2(vector<vector<int> > &dungeon) {
	int M = dungeon.size();
	int N = dungeon[0].size();
	// hp[i][j] represents the min hp needed at position (i, j)
	// Add dummy row and column at bottom and right side
	vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
	hp[M][N - 1] = 1;
	hp[M - 1][N] = 1;
	for (int i = M - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
			hp[i][j] = need <= 0 ? 1 : need;
		}
	}
	return hp[0][0];
}



int main(void) {

	vector<vector<int>> dungeon = {
		{ 0, -51, -51, 51 },
		{ -50, -1000, -1000, -51 }, 
		{ -150, -1000, -1000, 51 }, 
		{ 1000, -100, -100, 0 }
	};

	int res = calculateMinimumHP(dungeon);
	cout << res << endl;

	return 0;
}