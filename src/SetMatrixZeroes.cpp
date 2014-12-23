

#include <iostream>
#include <vector>

using namespace std;


void setZeroes(vector<vector<int> > &matrix) {

	int r = matrix.size();
	if (r == 0) return;
	int c = matrix[0].size();


	int min = matrix[0][0];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
	}

	int f = min - 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][j] = f;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (matrix[i][j] == f) {
				for (int k = 0; k < c; k++) {
					if (matrix[i][k] != f)
						matrix[i][k] = 0;
				}
				for (int k = 0; k < r; k++) {
					if (matrix[k][j] != f)
						matrix[k][j] = 0;
				}
				matrix[i][j] = 0;
			}
		}
	}
}


void setZeroes2(vector<vector<int> > &matrix) {


	int r = matrix.size();
	if (r == 0) return;
	int c = matrix[0].size();

	vector<int> zeros(c, 0);

	int i, j, k;
	for (i = 0; i < r; i++) {
		k = -1;
		for (j = 0; j < c; j++) {
			if (matrix[i][j] == 0) {
				zeros[j] = 1;
				k = j;
			}
		}
		if (k != -1) {
			for (k = 0; k < c; k++) {
				matrix[i][k] = 0;
			}
		}
		else {
			for (k = 0; k < c; k++) {
				matrix[i][k] *= !zeros[k];
			}
		}
	}
	for (i = 0; i < r; i++) {
		for (k = 0; k < c; k++) {
			matrix[i][k] *= !zeros[k];
		}
	}
}



int main(void)
{
	//[2147483647,2,9],[2,6,7],[1,8,8],[5,0,1],[9,6,0]
	//[1],[0]
	//[[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
	vector<vector<int>> matrix;
	vector<int> row1, row2, row3, row4, row5;
	row1.push_back(0);
	row1.push_back(0);
	row1.push_back(0);
	row1.push_back(5);

	row2.push_back(4);
	row2.push_back(3);
	row2.push_back(1);
	row2.push_back(4);

	row3.push_back(0);
	row3.push_back(1);
	row3.push_back(1);
	row3.push_back(4);

	row4.push_back(1);
	row4.push_back(2);
	row4.push_back(1);
	row4.push_back(3);

	row5.push_back(0);
	row5.push_back(0);
	row5.push_back(1);
	row5.push_back(1);

	//row.push_back(1);

	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);
	matrix.push_back(row4);
	matrix.push_back(row5);

	setZeroes2(matrix);



	return 0;
}

