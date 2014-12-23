
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> restoreIpAddresses(string s) {
	

	int size = s.size();
	int d4, d3, d2, d1;
	int p4, p3, p2, p1;

	vector<string> ips;

	p4 = size - 1;
	d4 = 0;
	while (size - p4 <= 3 && p4 >= 0) {
		int t4 = p4, f4 = 0;
		d4 = 0; 
		while (t4 < size) { d4 = d4 * 10 + s[t4] - '0'; t4++; }
		if ((d4 && s[p4] != '0') || (!d4 && (size - p4) == 1)) f4 = 1;
		
		d3 = 0;
		p3 = p4 - 1;
		while (d4 <= 255 && (p4 - p3) <= 3 && p3 >= 0 && f4) {
			int t3 = p3, f3 = 0;
			d3 = 0;
			while (t3 < p4) { d3 = d3 * 10 + s[t3] - '0'; t3++; }
			if ((d3 && s[p3] != '0') || (!d3 && (p4 - p3) == 1)) f3 = 1;

			d2 = 0;
			p2 = p3 - 1;
			while (d3 <= 255 && (p3 - p2) <= 3 && p2 >= 0 && f3) {
				int t2 = p2, f2 = 0;
				d2 = 0;
				while (t2 < p3) { d2 = d2 * 10 + s[t2] - '0'; t2++; }
				if ((d2 && s[p2] != '0') || (!d2 && (p3 - p2) == 1)) f2 = 1;

				d1 = 0;
				p1 = p2 - 1;
				while (d2 <= 255 && (p2 - p1) <= 3 && p1 >= 0 && f2) {
					int t1 = p1, f1 = 0;
					d1 = 0;
					while (t1 < p2) { d1 = d1 * 10 + s[t1] - '0'; t1++; }
					if ((d1 && s[p1] != '0') || (!d1 && (p2 - p1) == 1)) f1 = 1;


					if (d1 <= 255 && p1 == 0 && f1) {
						string ip = std::to_string(d1) + "." + std::to_string(d2) + "." + std::to_string(d3) + "." + std::to_string(d4);
						cout << ip << endl;
						ips.push_back(ip);
					}
					p1--;
				}
				p2--;
			}
			p3--;
		}
		p4--;
	}

	return ips;
}


int main(void)
{
	// 
	string s = "25525511135"; // ["0.10.0.10","0.100.1.0"]
	vector<string> ips;

	ips = restoreIpAddresses(s);



	return 0;
}
