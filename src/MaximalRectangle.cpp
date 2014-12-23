
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<char>> &matrix)
{
	if (matrix.size() == 0) return 0;
	int res = 0;
	int row = matrix.size(), col = matrix[0].size();

	vector<vector<int>> height(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++) {
		if (0 == i) {
			for (int j = 0; j < col; j++) {
				height[i][j] = matrix[i][j] == '1' ? 1 : 0;
			}
		}
		else {
			for (int j = 0; j < col; j++) {
				height[i][j] = matrix[i][j] == '1' ? height[i - 1][j] + 1 : 0;
			}
		}
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == '0') continue;
			int h = INT_MAX;
			for (int k = j; k < col && matrix[i][k] == '1'; k++) {
				h = min(h, height[i][k]);
				int area = h * (k - j + 1);
				if (area > res) res = area;
			}
		}
	}

	return res;
}

int maximalRectangle4(vector<vector<char>> &matrix) {
	if (matrix.size() == 0) return 0;
	int res = 0;
	int row = matrix.size(), col = matrix[0].size();
	vector<int> v;
	for (int i = 0; i < row; i++) {
		v.clear();
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == '0') {
				v.clear();
				continue;
			}
			int l = i, h = 0;
			while (l < row && matrix[l][j] == '1') { l++; h++; }
			
		}
	}

	return res;
}

int largestRectangleArea(vector<char> &h) {
	stack<int> S;
	h.push_back(0);
	int sum = 0;
	for (int i = 0; i < h.size(); i++) {
		if (S.empty() || h[i] > h[S.top()]) S.push(i);
		else {
			int tmp = S.top();
			S.pop();
			sum = max(sum, h[tmp] * (S.empty() ? i : i - S.top() - 1));
			i--;
		}
	}
	return sum;
}
int maximalRectangle2(vector<vector<char> > &matrix) {
	vector<vector<char> > d(matrix);
	for (int i = 0; i < d.size(); i++) {
		if (0 == i){
			for (int j = 0; j < d[i].size(); j++) {
				d[i][j] = d[i][j] == '1' ? 1 : 0;
			}
			continue;
		}
		for (int j = 0; j < d[i].size(); j++) {
			d[i][j] = d[i][j] == '1' ? d[i - 1][j] + 1 : 0;
		}
	}

	int rlt = 0;
	for (int i = 0; i < d.size(); i++) {
		rlt = max(rlt, largestRectangleArea(d[i]));
	}
	return rlt;
}

int maximalRectangle3(vector<vector<char> > &matrix) {
	if (matrix.empty())  return 0;

	const int m = matrix.size();
	const int n = matrix[0].size();
	vector<int> H(n, 0);
	vector<int> L(n, 0);
	vector<int> R(n, n);

	int ret = 0;
	for (int i = 0; i < m; ++i) {
		int left = 0, right = n;
		// H[j]相当于转化后的每一行的柱状图在相应位置上的高度
		// 如果某位置是0，则L[j]也是0。
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == '1') {
				++H[j];
				L[j] = max(L[j], left);
			}
			else {
				left = j + 1;
				H[j] = 0; L[j] = 0; R[j] = n;
			}
		}
		// 从右至左处理该行柱状图
		for (int j = n - 1; j >= 0; --j) {
			if (matrix[i][j] == '1') {
				R[j] = min(R[j], right);
				ret = max(ret, H[j] * (R[j] - L[j]));
				// cout<<ret<<endl;
			}
			else {
				right = j;
			}
		}
	}
	return ret;
}

int expand(vector<vector<char> > &d, int m, int n) {
	int h = 0;
	int j = n;
	//go up
	for (int i = m; i >= 0; --i) {
		if (d[i][j] >= d[m][n]) ++h;
		else break;
	}

	//go down
	for (int i = m + 1; i < d.size(); ++i) {
		if (d[i][j] >= d[m][n]) ++h;
		else break;
	}
	return h*d[m][n];
}

int maximalRectangle6(vector<vector<char> > &matrix) {
	vector<vector<char> > d(matrix);
	for (int i = 0; i < d.size(); i++) {
		d[i][0] = d[i][0] - '0';
		for (int j = 1; j < d[i].size(); j++) {
			d[i][j] = d[i][j] == '1' ? d[i][j - 1] + 1 : 0;
		}
	}

	int rlt = 0;
	for (int i = 0; i < d.size(); i++) {
		for (int j = 0; j < d[i].size(); j++) {
			if (d[i][j])
				rlt = max(rlt, expand(d, i, j));
		}
	}

	return rlt;
}

int main(void) {

	string lines[] = { "01101", "11010", "01110", "11110", "11111", "00000" };
	vector<vector<char>> matrix;
	for (int i = 0; i < 6; i++) {
		matrix.push_back(vector<char>(lines[i].begin(), lines[i].end()));
	}
	
	int res = maximalRectangle(matrix);

	return 0;
}