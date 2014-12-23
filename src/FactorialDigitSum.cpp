
#include <iostream>
#include <vector>

using namespace std;

int factorialDigitSum(int n) {
	if (n <= 1) return 1;
	vector<int> digit(n, 0);
	for (int i = 2; i <= n; i++) {
		int d = i;
		int j = 2;
		while (d > 1 && j <= i) {
			if (d % j == 0){
				digit[j]++;
				d /= j;
			}
			else j++;
		}
	}

	return 0;
}

int factorialDigitSum2(int n) {
	std::vector <int> digits(5000);
	int remainder = 0, sum = 0;
	digits[0] = 1;
	digits[1] = 1;
	for (int k = 2; k<n + 1; k++) {
		for (int i = 1; i <= digits[0]; i++) {
			digits[i] = digits[i] * k + remainder;
			remainder = 0;
			if (digits[i]>9) {
				remainder = digits[i] / 10;
				digits[i] %= 10;
				if (i == digits[0])
					digits[0]++;
			}
		}
	}
	for (int i = digits[0]; i >= 1; i--)
		sum += digits[i];
	return sum;
}

int main(void) {

	int res = factorialDigitSum2(1000);
	std::cout << res << std::endl;

	return 0;
}