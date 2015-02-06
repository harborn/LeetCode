#include <iostream>

using namespace std;

int numTrees(int n) {
	int *res = new int[n + 1];
	res[0] = 1;
	res[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		res[i] = 0;
		for (int j = 0; j < i; j++) {
			res[i] += res[j] * res[i-1-j];
		}
	}

	int ans = res[n];
	delete res;
	return ans;
}

int main(void)
{
	
	int res = numTrees(6);

	return 0;
}