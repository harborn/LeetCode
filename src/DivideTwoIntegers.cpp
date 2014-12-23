#include <iostream>


int divide(int dividend, int divisor) {
	if (dividend == 0) return 0;
	if (divisor == 1) return dividend;
	if (divisor == -1) return ~dividend + 1;
	if (dividend > 0 && divisor == 0) return INT_MAX;
	else if (dividend < 0 && divisor == 0) return INT_MIN;

	
	int isn = 0;
	long long dividend2 = dividend;
	long long divisor2 = divisor;
	if (dividend2 < 0) { dividend2 = ~dividend2 + 1; isn = 1; }
	if (divisor2 < 0) { divisor2 = ~divisor2 + 1; isn = !isn; }
	int div = ~divisor2 + 1;
	
	int ret;
	if (dividend2 < divisor2)
		ret = 0;
	else {
		ret = 1;
		while ((dividend2 + div + div) >= divisor2) {
			ret += ret;
			div += div;
		}
		ret = ret + divide(dividend2 + div, divisor2);
	}

	if (isn) ret = ~ret + 1;
	return ret;
}


int main(void)
{
	int a = INT_MIN / 2;
	int res = divide(INT_MAX, 2);

	return 0;
}