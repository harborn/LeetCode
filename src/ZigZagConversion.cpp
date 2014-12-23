
#include <iostream>
#include <string>

using namespace std;

string convert(string s, int nRows) {
	string ret;
	int len = s.length();
	
	if (s.length() <= nRows || nRows == 1)
	{
		ret = s;
		return ret;
	}
	
	int p1 = 0, p2 = 1;
	int step;
	for (int i = 0; i < nRows; i++)
	{
		step = 0;
		while (step < len + nRows) {
			p1 = step - i;
			if (p1 >= 0 && p1 < len && p1 != p2) ret.push_back(s[p1]);
			p2 = step + i;
			if (p2 < len && p2 != p1) ret.push_back(s[p2]);
			step += nRows + nRows - 2;
		}
	}

	return ret;
}

string convert2(string s, int nRows) {
	if (nRows <= 1)
		return s;

	const int len = (int)s.length();
	string *str = new string[nRows];

	int row = 0, step = 1;
	for (int i = 0; i < len; ++i)
	{
		str[row].push_back(s[i]);

		if (row == 0)
			step = 1;
		else if (row == nRows - 1)
			step = -1;

		row += step;
	}

	s.clear();
	for (int j = 0; j < nRows; ++j)
	{
		s.append(str[j]);
	}

	delete[] str;
	return s;
}

int main(void)
{
	char s[] = "ABCD";
	string ret = convert2(s, 3);
	cout << ret << endl;

	return 0;
}

