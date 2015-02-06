
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &num) {
	vector<vector<int>> res;
	int size = num.size();
	if (size < 3) return res;

	std::sort(num.begin(), num.end());

	for (int i = 0; i < size-2; i++) {
		int a = num[i];
		int t = 0-a;
		int j = i+1, k = size-1;
		int b, c;
		while (j < k) {
			if (num[j] + num[k] > t) {
				k--;
			} else if (num[j] + num[k] < t) {
				j++;
			} else {
				vector<int> v;
				v.push_back(a);
				v.push_back(num[j]);
				v.push_back(num[k]);
				res.push_back(v);

				int d1 = num[j];
				int d2 = num[k];
				j++; k--;
				while (j < size && num[j] == d1) j++;
				while (k >= 0 && num[k] == d2) k--;
			}
		}

		while (i+1 < size-2 && a == num[i+1]) i++;
	}

	return res;
}

int main(void)
{
	int A[] = {-1, -1, 0, 1, 1, 2, 2, -1, -4};
	int n = sizeof(A) / sizeof(int);
	vector<int> num;
	num.insert(num.begin(), A, A+n);

	vector<vector<int>> res = threeSum(num);

	return 0;
}