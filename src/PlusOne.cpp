
#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
	vector<int> res;
	int size = digits.size();
	if (size == 0) return res;
	int carry;
	carry = (digits.back() + 1) / 10;
	
	if (carry)
		digits.back() = 0;
	else 
		digits.back() += 1;
	int i = digits.size() - 2;
	while (i >= 0 && carry) {
		carry = (digits[i] + 1) / 10;
		digits[i] =  (digits[i] + 1) % 10;
		i--;
	}

	if (carry) {
		res.push_back(1);
	}
	for (int i = 0; i < digits.size(); i++) {
		res.push_back(digits[i]);
	}
	return res;
}

int main(void)
{
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);

	vector<int> res = plusOne(digits);

	return 0;
}
