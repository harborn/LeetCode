
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) {
	vector<string> res;
	int size = digits.size();
	if (size == 0) {
		res.push_back("");
		return res;
	}

	string ch = "abcdefghijklmnopqrstuvwxyz";
	vector<string> t;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < size; i++) {
		switch (digits[i]) {
		case '2':
			c1 = 0; c2 = 3;
			break;
		case '3': 
			c1 = 3; c2 = 6;
			break;
		case '4': 
			c1 = 6; c2 = 9;
			break;
		case '5': 
			c1 = 9; c2 = 12;
			break;
		case '6': 
			c1 = 12; c2 = 15;
			break;
		case '7': 
			c1 = 15; c2 = 19;
			break;
		case '8': 
			c1 = 19; c2 = 22;
			break;
		case '9': 
			c1 = 22; c2 = 26;
			break;
		default:
			c1 = 0; c2 = 0;
			break;
		}

		t.clear();
		t.insert(t.begin(), res.begin(), res.end());
		res.clear();
		for (int j = c1; j < c2; j++) {
			if (!t.empty()) {
				for (int k = 0; k < t.size(); k++) {
					res.push_back(t[k]+ch[j]);
				}
			}
			else {
				string s;
				s += ch[j];
				res.push_back(s);
			}
		}
	}

	return res;
}

int main(void)
{
	vector<string> res = letterCombinations("23456789");

	return 0;
}