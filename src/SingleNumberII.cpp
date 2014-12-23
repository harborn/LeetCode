
#include <iostream>

using namespace std;

int singleNumber(int A[], int n) {
	int bit[32] = { 0 };
	int mask[32] = { 0 };
	for (int i = 0; i < 32; i++) {
		mask[i] = 1 << i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 32; j++) {
			if (A[i] & mask[j]) bit[j] += 1;
		}
	}
	int ret = 0;
	for (int i = 0; i < 32; i++) {
		bit[i] %= 3;
		if (bit[i] != 0) {
			ret |= mask[i];
		}
	}

	return ret;
}


int main(void)
{
	int A[4] = { 3, 3, 3, 1 };
	int n = sizeof(A) / sizeof(int);
	int ret = 0;
	
	ret = singleNumber(A, n);

	return 0;
}
