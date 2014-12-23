
#include <iostream>

using namespace std;

int numDecodings(string s) {
	int size = s.size();
	if (size == 0) return 0;
	else if (size == 1) {
		if (s[0] == '0')  return 0;
		else return 1;
	}
	
	if (s[1] != '0') {
		int n1 = numDecodings(s.substr(1));
		int n2 = 0;
		if (((s[0] - '0') * 10 + s[1] - '0') <= 26) n2 = numDecodings(s.substr(2));
		return n1 + n2;
	}
	else return numDecodings(s.substr(2));
}

int check(char one)
{
	return (one != '0') ? 1 : 0;
}
int check(char one, char two)
{
	return (one == '1' || (one == '2' && two <= '6')) ? 1 : 0;
}

int numDecodings2(string s) {
	if (s.empty() || s[0] == '0') return 0;
	if (s.size() == 1) return check(s[0]);
	int fn = 0, fn_1 = 0, fn_2 = 1;
	fn_1 = (check(s[0]) * check(s[1])) + check(s[0], s[1]);
	for (int i = 2; i< s.size(); i++)
	{
		if (check(s[i])) fn += fn_1;
		if (check(s[i - 1], s[i])) fn += fn_2;
		if (fn == 0)
			return 0;
		fn_2 = fn_1;
		fn_1 = fn;
		fn = 0;
	}
	return fn_1;
}


int main(void)
{
	// "27"
	//string s = "9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253";
	string s = "93715976311287";
	//string s2 = s.substr(4);
	//cout << s2;

	int ret = numDecodings(s);
	int ret2 = numDecodings2(s);
	return 0;
}