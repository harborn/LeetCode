
#include <iostream>

using namespace std;

int jump(int A[], int n) {

	int maxPos = 0, lastMaxPos = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (i > lastMaxPos) {
			res++;
			lastMaxPos = maxPos;
		}
		if (i + A[i] > maxPos)
			maxPos = i + A[i];
	}
	return res;
}

int main(void) {


	return 0;
}
