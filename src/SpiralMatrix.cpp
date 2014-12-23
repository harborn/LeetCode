
#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {

	vector<int> res;
	int m = matrix.size();
	if (m == 0) return res;
	int n = matrix[0].size();

	int i = 0;
	int j = 0;
	int m1 = -1, m2 = m;
	int n1 = -1, n2 = n;
	while (1) {
		m1 += 1; m2 -= 1;
		n1 += 1; n2 -= 1;

		if (m1 > m2 || n1 > n2)
			break;

		i = m1;
		j = n1;
		while (j <= n2) { // left to right
			res.push_back(matrix[m1][j]);
			j++;
		}
		i = m1 + 1;
		while (i <= m2) { // up to down
			res.push_back(matrix[i][n2]);
			i++;
		}
		j = n2 - 1;
		while (m2 > m1 && j >= n1) { // right to left
			res.push_back(matrix[m2][j]);
			j--;
		}
		i = m2 - 1;
		while (n2 > n1 && i > m1) { // down to up
			res.push_back(matrix[i][n1]);
			i--;
		}
	}

	return res;
}

int main(void)
{

	//vector<vector<int>> matrix(3, vector<int>());

	//matrix[0].push_back(1); matrix[0].push_back(2); matrix[0].push_back(3);
	//matrix[1].push_back(4); matrix[1].push_back(5); matrix[1].push_back(6);
	//matrix[2].push_back(7); matrix[2].push_back(8); matrix[2].push_back(9);

	vector<vector<int>> matrix(3, vector<int>());
	matrix[0].push_back(7);
	matrix[1].push_back(9);
	matrix[2].push_back(6);

	vector<int> res = spiralOrder(matrix);

	return 0;
}