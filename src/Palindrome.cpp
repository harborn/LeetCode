
#include <string>

using namespace std;

bool isPalindrome(int x) {
	string s;
	bool ret = false;
	while (x) {
		s.push_back(x%10 + '0');
		x = x/10;
	}
	
	string::iterator i = s.begin(), j = s.end() - 1;
	while (i < j) {
		if (*i != *j) return false;
		i++; j--;
	}
	return true;
}

int main(void)
{

	int ret = isPalindrome(11);

	return 0;
}