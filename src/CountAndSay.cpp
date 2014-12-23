
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


string countAndSay(int n) {

	string res;
	if (n <= 0) return res;

	res.push_back('1');
	n--;
	
	char last = '#';
	int cnt = 0;
	while (n) {
		string ns;
		string s = res;
		cnt = 0;
		int p = 0;
		char c, lc = '#';
		int size = res.size();
		while (p < size) {
			c = s[p];
			if (c != lc) {
				if (cnt != 0) {
					string ts;
					ts.append(std::to_string(cnt));
					ts.push_back(lc);
					ns.append(ts);
				}
				lc = c;
				cnt = 1;
			} else {
				cnt++;
			}
			p++;
		}
		if (cnt != 0) {
			string ts;
			ts.append(std::to_string(cnt));
			ts.push_back(c);
			ns.append(ts);
		}
		res = ns;
		
		n--;
	}

	return res;
}

string countAndSay2(int n) {
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function  
	string seq = "1";
	int it = 1;
	while (it<n)
	{
		stringstream newSeq;
		char last = seq[0];
		int count = 0;
		for (int i = 0; i <= seq.size(); i++)
		{
			if (seq[i] == last)
			{
				count++;
				continue;
			}
			else
			{
				newSeq << count << last;
				last = seq[i];
				count = 1;
			}
		}
		seq = newSeq.str();
		it++;
	}
	return seq;
}

string countAndSay3(int n) {
	if (n < 1)return "";
	string prev = "1";
	for (int i = 2; i <= n; i++)
	{
		char curChar = prev[0];
		int times = 1;//curChar 出现的次数
		string tmpstr;
		prev.push_back('#');//处理边界条件
		for (int k = 1; k < prev.size(); k++)
		{
			if (prev[k] == curChar)
				times++;
			else
			{
				tmpstr += to_string(times);
				tmpstr.push_back(curChar);
				curChar = prev[k];
				times = 1;
			}
		}
		prev = tmpstr;
	}
	return prev;
}

int main(void)
{

	string res = countAndSay(8);

	//string res = countAndSay2(12);

	string res3 = countAndSay3(8);

	return 0;
}