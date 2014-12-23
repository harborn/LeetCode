
#include <iostream>

using namespace std;


double PowXn(double x, int n) {
    if (x <= 0.00001 && x >= -0.00001)
        return 0;
    if (x == 1)
        return 1;
    if (x == -1) {
        if (n % 2) return -1;
        else return 1;
    }
    double ret = 1;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            ret *= x;
        }
    } else if (n < 0) {
        n = 0-n;
        for (int i = 0; i < n; i++) {
            ret /= x;
        }
    }
        
    return ret;
}

double PowXn2(double x, int n) {
	if (n == 0)
		return 1;
	if (n<0) {
		n = -n;
		x = 1 / x;
	}
	return (n % 2 == 0) ? pow(x*x, n / 2) : x*pow(x*x, n / 2);
}

int main(void)
{
	double ret = INF;
	//ret = PowXn(-1.00000, 2147483647);
	ret = PowXn2(0, -1);

	return 0;
}
