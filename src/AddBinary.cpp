
#include <string>
#include <iostream>
using namespace std;

string addBinary(string a, string b) {
    string ret = "";
    int f = 0;
    char c = '0';
    string::iterator ia = a.end(), ib = b.end();
    while (ia != a.begin() && ib != b.begin()) {
        ia--; ib--;
        c = *ia - '0' + *ib + f;
        if (c == '2') {
            c = '0'; f = 1;
        } else if (c == '3') {
            c = '1'; f = 1;
        } else {
            f = 0;
        }
        ret.insert(0, 1, c);
    }
    while (ia != a.begin()) {
        ia--;
        c = *ia + f;
        if (c == '2') {
            c = '0'; f = 1;
		} else {
			f = 0;	
		}
        ret.insert(0, 1, c);
    }
    while (ib != b.begin()) {
        ib--;
        c = *ib + f;
        if (c == '2') {
            c = '0'; f = 1;
		} else {
			f = 0;
		}
        ret.insert(0, 1, c);
    }
	if (f)
        ret.insert(0, 1, '1');
        
    return ret;
}

int main(void)
{
	string s = "hello";
	s.insert(0, 1, 'a');
	s.insert(0, 1, 'b');
	s.insert(0, 1, 'c');
	string::iterator is = s.end();
	while (is != s.begin()) 
	{
		is--;
		cout << *is;
	}	
	cout << endl;
		
	cout << s << endl;


	string ret = addBinary("101111", "10");

	cout << ret << endl;

	return 0;
}