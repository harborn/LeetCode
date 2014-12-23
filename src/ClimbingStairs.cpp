
#include <iostream>

using namespace std;

int fib(int n) {
	if (n <= 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

int fib2(int c, int l, int n) {
	if (n <= 1) return c;
	return fib2(c + l, c, n - 1);
}

int fib3(int n) {
	if (n <= 1) return 1;
	int d[3] = { 1, 1 , 2};
	for (int i = 2; i < n; i++) {
		d[0] = d[1];
		d[1] = d[2];
		d[2] = d[1] + d[0];
	}
	return d[2];
}

int climbStairs(int n) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	else if (n == 2) return 2;

	//return climbStairs(n - 1) + climbStairs(n - 2);
	//return fib2(1, 1, n);
	return fib3(n);
}

int main(void)
{
	//fib3(10);


	for (int i = 0; i < 44; i++) {
		//int f = fib(i);
		int f2 = fib2(1, 1, i);
		int f3 = fib3(i);
		int res = climbStairs(i);
		cout << f2; cout << ", ";
		cout << f3; cout << ", ";
		cout << res << endl;

		//cout << f << ", " << f2 << ", " << endl;
	}

	return 0;
}