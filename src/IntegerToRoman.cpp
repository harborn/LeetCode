
#include <iostream>
#include <string>

using namespace std;


string helper(int num) {
	if (num <= 0) return "";
	if (num >= 1000) {
		return "M" + helper(num - 1000);
	}
	else if (num >= 500) {
		return "D" + helper(num - 500);
	}
	else if (num >= 100) {
		return "C" + helper(num - 100);
	} 
	else if (num >= 50) {
		return "L" + helper(num - 50);
	} 
	else if (num >= 10) {
		return "X" + helper(num - 10);
	}
	else if (num >= 5) {
		return "V" + helper(num - 5);
	}
	else {
		return "I" + helper(num - 1);
	}
}

string intToRoman(int num) {
	string res = helper(num);
	string res2;
	int i = 0, cnt = 0;
	char c, lc = 0;
	while (i < res.size()) {
		c = res[i];
		i++; cnt = 1;
		while (i < res.size() && res[i] == c) {
			i++; cnt++;
		}
		if (cnt == 4) {
			if (c == 'I') {
				if (lc == 'V') {
					res2.erase(res2.end() - 1);
					res2.append("IX");
					lc = 'X';
				}
				else {
					res2.append("IV");
					lc = 'V';
				}
			}
			else if (c == 'X') {
				if (lc == 'L') {
					res2.erase(res2.end() - 1);
					res2.append("XC");
					lc = 'C';
				}
				else {
					res2.append("XL");
					lc = 'L';
				}
			}
			else if (c == 'C') {
				if (lc == 'D') {
					res2.erase(res2.end() - 1);
					res2.append("CM");
					lc = 'M';
				}
				else {
					res2.append("CD");
					lc = 'D';
				}
			}
			else {
				string t(4, c);
				res2.append(t);
				lc = c;
			}
		}
		else {
			string t(cnt, c);
			res2.append(t);
			lc = c;
		}
	}

	return res2;
}

int main(void) {

	for (int i = 1; i <= 100; i++) {
		cout << i << ": " << intToRoman(i) << endl;
	}


	return 0;
}