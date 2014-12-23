
#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int n = gas.size();

	vector<int> left;
	for (int i = 0; i < n; i++) {
		left.push_back(gas[i] - cost[i]);
	}

	int start = 0;
	int sum = 0;
	for (int i = 0; i < 2*n && start < n; i++) {
		if (i - start >= n)
			return start;
		if (left[i%n] + sum < 0) {
			sum = 0;
			start = i+1;
		}
		else {
			sum += left[i%n];
		}
	}

	return -1;
}

int main(void)
{
	vector<int> gas;
	vector<int> cost;
	gas.push_back(2); //gas.push_back(2);
	cost.push_back(1); //cost.push_back(1);

	int res = canCompleteCircuit(gas, cost);

	return 0;
}
