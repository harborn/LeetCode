
#include <iostream>
#include <string>

using namespace std;

bool isNumber(const char *s) {
	if (s == NULL) return false;
	while (*s == ' ') s++;
	if (*s == '+' || *s == '-') s++;
	
	return true;
}

bool isNumber2(const char *s) {
	bool point = false, notation = false;
	int len = strlen(s);
	int start = 0, end = len;

	for (int i = start; i < end; i++) {
		if (s[i] == ' ') start++;
		else break;
	}

	for (int i = end - 1; i >= 0; i--) {
		if (s[i] == ' ') end--;
		else break;
	}

	if (start >= end) return false;
	if (s[start] == '+' || s[start] == '-') start++;
	if (s[start] == '.' && ((s[start + 1] < '0') || (s[start + 1] > '9')))
		return false;//special case  '.'

	/* this case is right in this problem
	if(s[start] > '9'|| s[start] < '0')
	return false;// in case ".0887"
	*/

	if (s[start] == 'e') return false;

	for (int i = start; i < end; i++){
		if (s[i] <= '9' && s[i] >= '0') continue;
		else if (s[i] == '.') {
			start = i + 1; // ex: 904.[4]2
			point = true;
			break;
		}
		else if (s[i] == 'e') {
			start = i + 1;
			if (s[start] == '+' || s[start] == '-')
				start++;
			notation = true;
			break;
		}
		else return false;
	}

	if (point) {
		if (start >= end) return true; //ex:  "90932."
		for (int i = start; i < end; i++) {
			if (s[i] <= '9' && s[i] >= '0') continue;
			else if (s[i] == 'e'){
				start = i + 1;
				if (s[start] == '+' || s[start] == '-')
					start++;
				notation = true;
				break;
			}
			else return false;
		}
	}

	if (notation) {
		if (start >= end) return false;
		else if (s[start] > '9' || s[start] < '0') return false;
		for (int i = start; i < end; i++) {
			if (s[i] <= '9' && s[i] >= '0') continue;
			else return false;
		}
	}

	return true;
}


bool isNumber3(const char *s) {
	bool has_dot = false, has_e = false, has_num = false;

	while (*s == ' ') s++;                                  // filter prefix ' '
	if (*s == '-' || *s == '+') s++;                        // filter operator '+' or '-'

	while (*s && *s != ' ') {
		if ((*s == 'e' || *s == 'E') && !has_e) {           // filter 'e'
			has_e = has_dot = true;
			if (!has_num) return false;                     // there should be a number before 'e'
			if (*(s + 1) == '-' || *(s + 1) == '+') s++;
			if (!isdigit(*(s + 1))) return false;
		}
		else if (*s == '.' && !has_dot) has_dot = true;
		else if (isdigit(*s)) has_num = true;
		else return false;
		s++;
	}

	while (*s) if (*s++ != ' ') return false;               // filter suffix ' '

	return has_num;
}

bool isNumber4(string str) {
	int state = 0, flag = 0; // flag to judge the special case "."
	while (str[0] == ' ')  str.erase(0, 1);//delete the  prefix whitespace 
	while (str[str.length() - 1] == ' ') str.erase(str.length() - 1, 1);//delete the suffix whitespace
	for (int i = 0; i < str.length(); i++){
		if ('0' <= str[i] && str[i] <= '9'){
			flag = 1;
			if (state <= 2) state = 2;
			else state = (state <= 5) ? 5 : 7;
		}
		else if ('+' == str[i] || '-' == str[i]){
			if (state == 0 || state == 3) state++;
			else return false;
		}
		else if ('.' == str[i]){
			if (state <= 2) state = 6;
			else return false;
		}
		else if ('e' == str[i]){
			if (flag && (state == 2 || state == 6 || state == 7)) state = 3;
			else return false;
		}
		else return false;
	}
	return (state == 2 || state == 5 || (flag&&state == 6) || state == 7);
}

int main(void) {

	string ss[] = {
		"2e10", // true
		" 0", // true
		"  0.1", // true
		" abc", // false
		" 1 a", // false
		" 2e10", // true
		"e9", // false
		".1", // true
		".", // false
		"01", // true
		"3.", // true
		"0.", // true
		"0123", // true
		"+123", // true
		"-123", // true
		"2e+10", // true
		"2e-10", // true
		".e10", // true
	};
	int n = 18;

	bool ret;
	ret = isNumber("0.");

	for (int i = 0; i < n; i++) {
		cout << ss[i] << "\t\t: ";
		ret = isNumber2(ss[i].c_str());
		if (ret) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}