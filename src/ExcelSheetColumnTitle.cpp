
#include <iostream>
#include <string>

using namespace std;

string convertToTitle(int n) {
	if (n <= 0) return "";
	string res;
	while (n > 0) {
		n--;
		int r = n % 26;
		res.insert(res.begin(), 'A' + r);
		n /= 26;
	}
	return res;
}

int main(void) {

	for (int i = 1; i <= 1000; i++) {
		string res = convertToTitle(i);
		cout << i << " -> " << res << endl;
	}

	return 0;
}

