
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string s) {
	int size = s.size();
	if (size == 0) return true;

	int t1 = 0, t2 = 0, t3 = 0;
	int i = 0;
	while (i < size) {
		if (s[i] == '(') t1++;
		else if (s[i] == ')') {
			t1--; 
			if (t1 < 0) return false;
			else if (t1 == 0 && (t2 || t3)) return false;
		}
		else if (s[i] == '[') t2++;
		else if (s[i] == ']') {
			t2--; 
			if (t2 < 0) return false;
			else if (t2 == 0 && (t1 || t3)) return false;
		}
		else if (s[i] == '{') t3++;
		else if (s[i] == '}') {
			t3--; 
			if (t3 < 0) return false;
			else if (t3 == 0 && (t1 || t2)) return false;
		}
		i++;
	}

	if (t1 || t2 || t3) return false;
	return true;
}


bool isValid2(string s)
{
	int size = s.size();
	if (size == 0) return 0;
	string ts;
	
	int i = 0;
	while (i < size) {
		char sc = s[i];
		if (ts.empty())
			ts.push_back(sc);
		else 
		{
			char tc = ts.back();
			if ((tc == '[' && sc == ']') ||
				(tc == '(' && sc == ')') ||
				(tc == '{' && sc == '}'))
				ts.pop_back();
			else
				ts.push_back(sc);
		}
		i++;
	}
	if (ts.empty()) return true;
	else return false;
}

int main(void)
{
	string s = "([)]";

	bool res = isValid2(s);

	return 0;
}
