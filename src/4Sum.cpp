
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int>> res;
	int size = num.size();
	if (size < 4) return res;
	sort(num.begin(), num.end());
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {
				for (int l = k + 1; l < size; l++) {
					int sum = num[i] + num[j] + num[k] + num[l];
					if (sum == target) {
						vector<int> ans(4);
						ans[0] = num[i]; ans[1] = num[j];
						ans[2] = num[k]; ans[3] = num[l];
						res.push_back(ans);
					}
				}
			}
		}
	}

	return res;
}

vector<vector<int>> fourSum2(vector<int> &num, int target) {
	vector<vector<int>> res;
	int size = num.size();
	if (size < 4) return res;
	sort(num.begin(), num.end());

	for (int i = 0; i < size - 3; i++) {
		for (int j = i + 1; j < size - 2; j++) {
			int t2 = target - num[i] - num[j];
			int s = j + 1, e = size - 1;
			while (s < e) {
				if (num[s] + num[e] > t2) {
					e--;
				}
				else if (num[s] + num[e] < t2) {
					s++;
				}
				else {
					vector<int> ans(4);
					ans[0] = num[i]; ans[1] = num[j];
					ans[2] = num[s]; ans[3] = num[e];
					res.push_back(ans);
					while (s < e && num[s] == num[s + 1]) s++;
					while (e > s && num[e] == num[e - 1]) e--;
					s++; e--;
				}
			}
			while (j < size - 3 && num[j] == num[j + 1]) j++;
		}
		while (i < size - 4 && num[i] == num[i + 1]) i++;
	}

	return res;
}

int main(void) {

	//int A[] = { 1, 0, -1, 0, -2, 2 };
	//int A[] = { -430, -407, -404, -370, -364, -343, -291, -263, -257, -242, -213, -212, -210, -209, -172, -144, -85, -79, -70, -36, -34, -14, 0, 18, 31, 36, 45, 45, 83, 117, 120, 134, 153, 178, 186, 197, 208, 223, 234, 263, 264, 313, 341, 382, 388, 421, 427, 439, 445, 451, 458, 467, 474, 480 };
	int A[] = { -1, 0, -5, -2, -2, -4, 0, 1, -2 };
	int n = sizeof(A) / sizeof(int);

	vector<int> num(A, A + n);

	vector<vector<int>> res = fourSum2(num, -9);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ", ";
		}
		cout << endl;
	}

	return 0;
}