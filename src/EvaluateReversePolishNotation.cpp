
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string> &tokens) {
	stack<int> st;

	int size = tokens.size();
	int i = 0;
	while (i < size) {
		if (tokens[i] == "+") {
			if (st.size() >= 2) {
				int i1 = st.top(); st.pop();
				int i2 = st.top(); st.pop();
				st.push(i1 + i2);
			}
		} 
		else if (tokens[i] == "-") {
			if (st.size() >= 2) {
				int i1 = st.top(); st.pop();
				int i2 = st.top(); st.pop();
				st.push(i2 - i1);
			}
		}
		else if (tokens[i] == "*") {
			if (st.size() >= 2) {
				int i1 = st.top(); st.pop();
				int i2 = st.top(); st.pop();
				st.push(i1 * i2);
			}
		}
		else if (tokens[i] == "/") {
			if (st.size() >= 2) {
				int i1 = st.top(); st.pop();
				int i2 = st.top(); st.pop();
				st.push(i2 / i1);
			}
		} 
		else {
			st.push(atoi(tokens[i].c_str()));
		}
		i++;
	}
	return st.top();
}

int main(void)
{
	//string t[] = { "2", "1", "+", "3", "*" };
	string t[] = { "4", "13", "5", "/", "+" };

	vector<string> tokens;
	tokens.insert(tokens.begin(), t, t + 5);

	int res = evalRPN(tokens);

	return 0;
}