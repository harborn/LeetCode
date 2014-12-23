
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
	int size = prices.size();
	vector<int> left;
	left.push_back(0);
	left.push_back(0);
	int sum = 0;
	int max = INT_MIN;
	for (int i = 1; i < size; i++) {
		sum += prices[i] - prices[i - 1];
		if (sum > 0) {
			if (sum > max) max = sum;
		}
		else {
			sum = 0;
		}
		left.push_back(max);
	}

	vector<int> right(size, 0);
	sum = 0;
	max = INT_MIN;
	for (int i = size - 1; i > 0; i--) {
		sum += prices[i] - prices[i - 1];
		if (sum > 0) {
			if (sum > max) max = sum;
		}
		else {
			sum = 0;
		}
		right[i] = max;
	}

	max = 0;
	sum = 0;
	for (int i = 0; i < size; i++) {
		sum = left[i] + right[i];
		if (sum > max) max = sum;
	}

	return max;
}

int findMax(vector<int> &diff) {
	int size = diff.size();
	int max = INT_MIN;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += diff[i];
		if (sum > 0) {
			if (sum > max) max = sum;
		}
		else {
			sum = 0;
		}
	}
	return max;
}

int main(void)
{
	//int A[] = { 1, 4, 2 };
	//int A[] = { 6, 1, 3, 2, 4, 7 };
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//int A[] = { 6, 1, 3, 2, 4, 7, 9, 6, 1, 7 };
	//int A[] = { 0, -5, 2, -1, 2, 3, 2, -3, -5, 6 };
	int n = sizeof(A) / sizeof(int);

	vector<int> diff;
	diff.insert(diff.begin(), A, A + n);

	vector<int> prices;
	prices.insert(prices.begin(), A, A + n);

	//int res = findMax(diff);
	int res = maxProfit(prices);


	return 0;
}
