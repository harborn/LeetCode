
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
	
	int l = s.size();
	if (l <= 0) return true;
	
	string s2;
	int d = 'a' - 'A';
	int i = 0; 
	while (i < l) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s2.push_back(s[i]);
		} else if (s[i] >= 'a' && s[i] <= 'z') {
			s2.push_back(s[i] - d);
		} else if (s[i] >= '0' && s[i] <= '9') {
			s2.push_back(s[i]);
		}
		i++;
	}

	i = 0; 
	int j = s2.size() - 1;
	while (i < j) {
		if (s2[i] != s2[j])
			return false;
		i++; j--;
	}
	return true;
}

int main(void)
{
	string s = "1a2";

	bool res = isPalindrome(s);



	return 0;
}