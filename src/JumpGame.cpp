
#include <iostream>

using namespace std;

bool canJump(int A[], int n) {
	int maxPos = 0;
	for (int i = 0; i <= maxPos && i < n; i++) {
		if (i + A[i] > maxPos) maxPos = i + A[i];
		if (maxPos >= n-1)
			return true;
	}
	return false;
}

int main(void)
{


	return 0;
}
