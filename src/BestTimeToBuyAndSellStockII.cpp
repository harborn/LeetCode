
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
	int size = prices.size();
	if (size == 0) return 0;

	int res = 0;
	for (int i = 1; i < size; i++) {
		int d = prices[i] - prices[i-1];
		if (d > 0) 
			res += d;
	}
	return res;
}

int main(void)
{


	return 0;
}