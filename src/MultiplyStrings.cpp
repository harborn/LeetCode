
#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
	int l1 = num1.size();
	int l2 = num2.size();
	if (l1 == 0 || l2 == 0) return "";
	if (!num1.compare("0") || !num2.compare("0"))
		return "0";
	
	if (!num1.compare("1")) return num2;
	if (!num2.compare("1")) return num1;

	if (l1 > l2) {
		string t = num1;
		num1 = num2;
		num2 = t;
		int l = l1;
		l1 = l2;
		l2 = l;
	}

	int step = 1;
	string lt = "";
	for (int i = l1-1; i >= 0; i--) {
		
		int carry = 0;
		int n1 = num1[i] - '0';
		string t;
		int v;
		for (int j = l2-1; j >= 0; j--) {
			v = n1 * (num2[j] - '0') + carry;
			t.insert(t.begin(), v % 10 + '0');
			carry = v / 10;
		}
		if (carry) 
			t.insert(t.begin(), carry + '0');
		v = l1-1-i;
		while (v--) t.push_back('0');

		carry = 0;
		int b1 = lt.size() - 1;
		int b2 = t.size() - 1;
		string nt;
		while (b1 >= 0 && b2 >= 0) {
			v = lt[b1] - '0' + t[b2] - '0' + carry;
			nt.insert(nt.begin(), v % 10 + '0');
			carry = v / 10;
			b1--; b2--;
		}
		while (b1 >= 0) {
			v = lt[b1] - '0' + carry;
			nt.insert(nt.begin(), v % 10 + '0');
			carry = v / 10;
			b1--;
		}
		while (b2 >= 0) {
			v = t[b2] - '0' + carry;
			nt.insert(nt.begin(), v % 10 + '0');
			carry = v / 10;
			b2--;
		}
		if (carry)
			nt.insert(nt.begin(), carry + '0');

		lt = nt;

	}
	
	return lt;
}

int main(void)
{

	string res = multiply("123", "456");

	return 0;
}