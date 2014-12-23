

#include <string>
#include <iostream>

using namespace std;
void reverseWords(string &s) {
	
	string::iterator i = s.begin(), j = s.end() - 1;
	char c;

	while (*j == ' ') {
		s.erase(j); j--;
	}
	while (*i == ' ') {
		s.erase(i);
	}
	
	j = i;
    while (j < s.end()) {
		i = j;
		while (j < s.end()) {
			if (*j != ' ') j++;
			else {
				j--; break;
			}
		}
	
		string::iterator ti, tj;
		ti = i; tj = j;
		while (ti < tj) {
			c = *ti;
			*ti = *tj;
			*tj = c;
			ti++; tj--;
		}
		j++;
		
		if (j != s.end()) j++;

		while (j != s.end() && *j == ' ') s.erase(j);

		if (j != s.end()) j++;
    }
}

void reverseWords2(string &s)
{
	string ret;
	string::iterator i = s.begin(), j = s.end() - 1;
	char c;

	while (*j == ' ') {
		s.erase(j); j--;
	}
	while (*i == ' ') {
		s.erase(i);
	}

	while (j < s.end()) {
		i = j;
		while (j < s.end()) {
			if (*j != ' ') j++;
			else {
				j--; break;
			}
		}
		
		string::iterator tj;
		while (tj > i) {
			ret.push_back(*tj); *tj--;
		}
		
	}

}

int main(void)
{
	string s = "a";
	reverseWords(s);

	cout << "|" + s + "|" << endl;

	return 0;
}

