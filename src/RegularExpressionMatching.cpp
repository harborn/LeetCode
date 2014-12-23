
#include <iostream>

bool isMatch2(const char *s, const char *p) {

	int last = 256;
	while (*s != '\0' && *p != '\0') {

		if (*p == '*') {
			while (*(p + 1) == '*') p++; // remove all consecutive '*'

			if (last == 256) break;
			if (*s != last) {
				p++;
			}
			else if (*s != *(s + 1)) {
				s++; p++;
			}
			else {
				int sl = 0;
				while (*s == last) {
					s++;
					sl++;
				}
				
				const char *p2 = p;
				while (*(p2 + 1) != '\0' && (*(p2 + 2) == '*')) {
					p2 += 2;
					while (*(p2+1) == '*') p2++;
				}
				p2 += 1;
				int pl = 0;
				while (*p2 == last) { p2++; pl++; }
				if (pl <= sl) p = p2 + 1;
				else return false;
			}
		}
		else if (*p == '.') {
			last = '.';
			s++; p++;
		}
		else if (*s == *p) {
			last = *s;
			if (*(p + 1) == '*') {
				p++;
			}
			else {
				s++; p++;
			}
		}
		else
		{
			if (*(p + 1) == '*') {
				last = *p;
				p++;
			}
			else break;
		}
	}

	if (*s != '\0' || *p != '\0') return false;
	return true;
}

bool matchChar(const char *s, const char *p) {
	return *s != '\0' && (*p == '.' || *p == *s);
}

bool isMatch3(const char *s, const char *p) {
	if (*p == '\0') return *s == '\0';
	if (*(p + 1) == '*') {
		if (isMatch3(s, p + 2))
			return true;
		while (matchChar(s, p)) {
			if (isMatch3(++s, p+2))
				return true;
		}
		return false;
	}
	else {
		if (matchChar(s, p))
			return isMatch3(s + 1, p + 1);
		return false;
	}
}

bool isMatch3_1(const char *s, const char *p) {
	if (*p == '\0') return *s == '\0';
	if (*(p + 1) == '*') {
		if (isMatch3_1(s, p + 2))
			return true;
		if (matchChar(s, p))
			return isMatch3_1(++s, p);
		else return false;
	}
	else {
		if (matchChar(s, p))
			return isMatch3_1(s + 1, p + 1);
		return false;
	}
}


bool isMatch4(const char *s, const char *p) {
	for (char c = *p; c != 0; ++s, c = *p) {
		if (*(p + 1) != '*')
			p++;
		else if (isMatch4(s, p + 2))
			return true;
		if ((*s == 0) || ((c != '.') && (c != *s)))
			return false;
	}
	return *s == 0;
}

bool matchFirst(const char *s, const char *p){
	return (*p == *s || (*p == '.' && *s != '\0'));
}

bool isMatch5(const char *s, const char *p) {
	if (*p == '\0') return *s == '\0';  //empty

	if (*(p + 1) != '*') { //without *
		if (!matchFirst(s, p)) return false;
		return isMatch5(s + 1, p + 1);
	}
	else { //next: with a *
		if (isMatch5(s, p + 2)) 
			return true;    //try the length of 0
		while (matchFirst(s, p)) { //try all possible lengths 
			if (isMatch5(++s, p + 2))
				return true;
		}
		return false;
	}
}

bool isMatch(const char *s, const char *p) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function 
	if (*p == '*') {
		return false;//error patten
	}
	else if (*p == '\0') {
		return *s == '\0';
	}
	else if (*p == '.') {
		char cpnext = *(p + 1);
		if (cpnext == '*') {
			if (*(p + 2) == '\0') return true;
			for (const char *snext = s;; ++snext) {
				bool match = isMatch(snext, p + 2);
				if (match) return true;
				if (*snext == '\0') return false;
			}
		}
		else {
			return (*s != '\0') && isMatch(s + 1, p + 1);
		}
	}
	else {
		//*p is a normal character
		char cpnext = *(p + 1);
		if (cpnext == '*') {
			//have a star after a normal character
			for (const char *snext = s;; ++snext) {
				bool match = isMatch(snext, p + 2);
				if (match) return true;
				if (*snext != *p) return false;
			}
		}
		else {
			//standard situation
			return (*p == *s) && isMatch(s + 1, p + 1);
		}
	}
}

int main(void)
{
	using namespace std;

	bool res;

	//res = isMatch3("aa", "a"); cout << res << endl;
	//res = isMatch3("aa", "aa"); cout << res << endl;
	//res = isMatch3("aaa", "aa"); cout << res << endl;
	//res = isMatch3("aa", "a*"); cout << res << endl;
	//res = isMatch3("aa", ".*"); cout << res << endl;
	//res = isMatch3("ab", ".*"); cout << res << endl;
	//res = isMatch3("aab", "c*a*b"); cout << res << endl;
	//res = isMatch3("aaa", "a*a"); cout << res << endl;
	//res = isMatch3("aaa", "ab*a*c*a"); cout << res << endl;
	//res = isMatch3("ab", ".*c"); cout << res << endl;

	res = isMatch3_1("aa", "a*"); cout << res << endl;

	return 0;
}
