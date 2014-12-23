
#include <iostream>

using namespace std;

void sortColors(int A[], int n) {

	int red = 0;
	int blue = n - 1;
	int i = 0;

	while (i <= blue) {
		if (A[i] == 0) {
			std::swap(A[i], A[red]);
			red++;
			i++;
		}
		else if (A[i] == 2) {
			std::swap(A[i], A[blue]);
			blue--;
		}
		else {
			i++;
		}
	}
}




int main(void)
{
	int A[] = { 1, 0 };
	int n = sizeof(A) / sizeof(int);

	sortColors(A, n);


	return 0;
}