#include <iostream>
using namespace std;



int trailingZeroes(int n) {
	int res = 0;
	int tn = 0, fn = 0;
	for (int i = 2; i <= n; i++) {
		int num = i;
		while (num % 10 == 0) {
			res += 1;
			num /= 10;
		}
		while (num) {
			if (num % 5 == 0) {
				fn++;
				num /= 5;
			} else if (num % 2 == 0) {
				tn++;
				num /= 2;
			} else {
				break;
			}
		}
	}
	if (tn < fn) res += tn;
	else res += fn;

	return res;
}

int trailingZeroes2(int n) {
	return n == 0 ? 0 : n / 5 + trailingZeroes2(n / 5);
}

int helper(int n, int res)
{
	if (!n) return res;
	return helper(n / 5, res + n / 5);
}

int trailingZeroes3(int n) {
	int res = 0;
	return helper(n, 0);
}

int main(void) {

	cout << trailingZeroes2(20) << endl;

	for (int i = 1; i <= 30; i++) {
		int res = trailingZeroes3(i);
		cout << i << " = " << res << endl;
	}

	return 0;
}