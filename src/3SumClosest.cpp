
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &num, int target) {
	int size = num.size();

	int closest = INT_MAX;
	int diff = INT_MAX;

	std::sort(num.begin(), num.end());

	for (int i = 0; i < size-2; i++) {
		int j = i+1, k = size-1;
		while (j < k) {
			int sum = num[i] + num[j] + num[k];

			if (sum > target) {
				if (sum-target < diff) {
					closest = sum;
					diff = sum-target;
				}
				k--;
			} else if (sum < target) {
				if (target-sum < diff) {
					closest = sum;
					diff = target-sum;
				}
				j++;
			} else {
				diff = 0;
				closest = target;
				k--; j++;
			}
		}
		while (i+1 < size-2 && num[i+1] == num[i]) i++;
	}

	return closest;
}

int main(void)
{
	int A[] = {-1,2,1,-4};
	int n = sizeof(A) / sizeof(int);

	vector<int> num;
	num.insert(num.begin(), A, A+n);

	int res = threeSumClosest(num, 1);

	return 0;
}