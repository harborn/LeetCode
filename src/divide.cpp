
#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
	if (dividend > 0 && divisor == 0) return 2147483647;
    else if (dividend < 0 && divisor == 0) return ~2147483647;

	if (divisor == 1) return dividend;
	else if (divisor == -1) return ~dividend + 1;
	
	if (dividend < divisor) return 0;

    

	int isn = 0;
	if (dividend < 0) {dividend = ~dividend + 1; isn = 1;}
	if (divisor < 0) {divisor = ~divisor + 1; isn = !isn;}

    int div = ~divisor + 1;
	int ret = 1;
	while ((dividend + div) >= divisor) {
		dividend = dividend + div;
        ret += ret;
		div += div;
    }

	ret = ret + divide(dividend, divisor);

	if (isn) ret = ~ret + 1;
    return ret;
}

int main(void)
{

	cout << divide(2147483647, 2) << endl;

	return 0;
}