
#include <iostream>

int reverse(int x) {
	long t, isn = 0;
	if (x < 0) { t = 0 - x; isn = 1; }
	else t = x;

	long long ret = 0;
	while (t) {
		ret = ret * 10 + t % 10;
		t = t / 10;
	}
	if (isn) ret = 0 - ret;
	if (ret > INT_MAX || ret <= INT_MIN) return 0;
	return ret;
}

int main(void) {

	int x = -1534236469;
	
	int res = reverse(x);


	return 0;
}