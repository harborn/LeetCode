
#include <iostream>

using namespace std;

bool matchChar(const char *s, const char *p) {
	return (*p == '*') || (*s != '\0' && (*p == '?' || *p == *s));
}

bool isMatch(const char *s, const char *p) {
	if (*p == '\0') return *s == '\0';
	if (*s == '\0') return *p == '\0' || (*p == '*' && *(p + 1) == '\0');
	if (*p == '*') {
		if (isMatch(s, p + 1))
			return true;
		return isMatch(s + 1, p);
	}
	else {
		if (matchChar(s, p))
			return isMatch(s + 1, p + 1);
		return false;
	}
}

bool isMatch2(const char *s, const char *p) {
	const char* star = NULL;
	const char* ss = s;
	while (*s){
		//advancing both pointers when (both characters match) or ('?' found in pattern)
		//note that *p will not advance beyond its length 
		if ((*p == '?') || (*p == *s)){ s++; p++; continue; }

		// * found in pattern, track index of *, only advancing pattern pointer 
		if (*p == '*'){ star = p++; ss = s; continue; }

		//current characters didn't match, last pattern pointer was *, current pattern pointer is not *
		//only advancing pattern pointer
		if (star){ p = star + 1; s = ++ss; continue; }

		//current pattern pointer is not star, last patter pointer was not *
		//characters do not match
		return false;
	}

	//check for remaining characters in pattern
	while (*p == '*'){ p++; }

	return !*p;
}

// not complete.
bool isMatch3(const char *s, const char *p) {
	const char *start;
	while (*s != '\0' && *p != '\0') {
		if (*p == '?' || *p == *s) { s++; p++; }
		else if (*p == '*') {
			while (*p == '*') p++;
			if (*p == '\0') 
				while (*s != '\0') s++;
			else {
				start = s;
				while (*s == *p) s++;
				//
			}
		}
		else break;
	}

	if (*p == '\0') return *s == '\0';
	if (*s == '\0') return *p == '\0' || (*p == '*' && *(p + 1) == '\0');
	return false;
}

int main(void)
{
	bool res;

	cout << "match1: " << endl;
	res = isMatch3("hi", "*?"); cout << res << endl;
	res = isMatch3("hi", "*??"); cout << res << endl;
	res = isMatch3("hi", "*???"); cout << res << endl;
	res = isMatch3("aa", "a"); cout << res << endl;
	res = isMatch3("aa", "aa"); cout << res << endl;
	res = isMatch3("aaa", "aa"); cout << res << endl;
	res = isMatch3("aa", "*"); cout << res << endl;
	res = isMatch3("aa", "a*"); cout << res << endl;
	res = isMatch3("ab", "?*"); cout << res << endl;
	res = isMatch3("aab", "c*a*b"); cout << res << endl;
	res = isMatch3("b", "?*?"); cout << res << endl;
	res = isMatch3("b", "*a*"); cout << res << endl;
	res = isMatch3("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"); cout << res << endl;

	cout << "match2: " << endl;

	res = isMatch2("aa", "a"); cout << res << endl;
	res = isMatch2("aa", "aa"); cout << res << endl;
	res = isMatch2("aaa", "aa"); cout << res << endl;
	res = isMatch2("aa", "*"); cout << res << endl;
	res = isMatch2("aa", "a*"); cout << res << endl;
	res = isMatch2("ab", "?*"); cout << res << endl;
	res = isMatch2("aab", "c*a*b"); cout << res << endl;
	res = isMatch2("b", "?*?"); cout << res << endl;
	res = isMatch2("b", "*a*"); cout << res << endl;
	res = isMatch2("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"); cout << res << endl;



	return 0;
}