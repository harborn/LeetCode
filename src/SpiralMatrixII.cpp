
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {

	vector<vector<int>> res(n, vector<int>(n));

	int i = 0;
	int j = 0;
	int m1 = -1, m2 = n;
	int n1 = -1, n2 = n;
	int cnt = 1;
	while (1) {
		m1 += 1; m2 -= 1;
		n1 += 1; n2 -= 1;

		if (m1 > m2 || n1 > n2)
			break;

		i = m1;
		j = n1;
		while (j <= n2) { // left to right
			res[m1][j] = cnt++;
			j++;
		}
		i = m1 + 1;
		while (i <= m2) { // up to down
			res[i][n2] = cnt++;
			i++;
		}
		j = n2 - 1;
		while (m2 > m1 && j >= n1) { // right to left
			res[m2][j] = cnt++;
			j--;
		}
		i = m2 - 1;
		while (n2 > n1 && i > m1) { // down to up
			res[i][n1] = cnt++;
			i--;
		}
	}
	
	return res;
}

int main(void)
{


	vector<vector<int>> res = generateMatrix(3);

	return 0;
}