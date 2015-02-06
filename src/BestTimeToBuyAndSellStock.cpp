
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
	
	int size = prices.size();
	if (size == 0) return 0;
	vector<int> pd;
	pd.push_back(0);
	for (int i = 1; i < size; i++) {
		pd.push_back(prices[i]-prices[i-1]);
	}
	int max = 0;
	int sum = 0;
	for (int i = 1; i < size; i++) {
		sum += pd[i];
		if (sum > 0) {
			if (sum > max)
				max = sum;
		} else {
			sum = 0;
		}
	}
	return max;
}

int maxProfit2(vector<int> &prices) {
	int size = prices.size();
	if (size == 0) return 0;
	int max = 0, sum = 0;
	for (int i = 1; i < size; i++) {
		sum += prices[i]-prices[i-1];
		if (sum > 0) {
			if (sum > max) max = sum;
		} else {
			sum = 0;
		}
	}
	return max;
}

int main(void)
{
	int A[] = {2,1};
	int n = sizeof(A) / sizeof(int);

	vector<int> prices;
	prices.insert(prices.begin(), A, A+n);

	int res = maxProfit(prices);

	return 0;
}
