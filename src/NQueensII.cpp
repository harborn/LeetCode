
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void helper(int &res, vector<string> &sol, int r, int n) {
	if (r == n)
		res++;

	// create a line
	string line(n, '.');
	string line2(n, '.');
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			if (sol[j][i] == 'Q') {
				line[i] = 'Q';
				break;
			}
			else if ((i - r + j >= 0 && sol[j][i - r + j] == 'Q') ||
				(i + r - j) < n && sol[j][i + r - j] == 'Q') {
				line[i] = 'N';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (line[i] == '.') {
			line2[i] = 'Q';
			sol.push_back(line2);
			helper(res, sol, r + 1, n);
			sol.pop_back();
			line2[i] = '.';
		}
	}
}

int totalNQueens(int n) {
	int res = 0;
	if (n <= 0) return res;
	vector<string> sol;
	helper(res, sol, 0, n);
	return res;
}

int main(void) {

	int res = totalNQueens(8);


	return 0;
}