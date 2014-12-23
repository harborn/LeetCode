
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
	int size = s.size();
	int res = 0;
	if (size < 2) return res;
	int start = 0;
	stack<int> st;
	for (int i = 0; i < size; i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else {
			if (st.empty()) {
				start = i+1;
			}
			else {
				st.pop();
				if (st.empty()) {
					res = max(res, i - start + 1);
				}
				else {
					res = max(res, i - st.top());
				}
			}
		}
	}

	return res;
}

int longestValidParentheses2(string s) {
	const char* str = s.c_str();
	int nMax = 0;
	const char *p = str;
	vector<const char*> sta;
	while (*p != '\0')
	{
		if (*p == '(')
		{
			sta.push_back(p);
		}
		else
		{
			if (!sta.empty() && *sta.back() == '(')
			{
				sta.pop_back();
				nMax = max(nMax, p - (sta.empty() ? str - 1 : sta.back()));
			}
			else
			{
				sta.push_back(p);
			}
		}
		p++;
	}
	return nMax;
}

int main(void)
{
	vector<string> vs;
	vs.push_back("(()"); // (()
	//vs.push_back("()()()))(()()()()"); // (()()()()
	vs.push_back(")()())"); // 
	vs.push_back(")("); // (
	vs.push_back("(()("); // (()(
	vs.push_back("()(()"); // ()(()
	vs.push_back("()(()("); // ()(()(
	vs.push_back("(((((()))))))()(()"); // ()(()

	for (int i = 0; i < vs.size(); i++) {
		int res = longestValidParentheses(vs[i]);
		cout << res << endl;
	}
	return 0;

}
