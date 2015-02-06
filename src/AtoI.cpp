
#include <iostream>

using namespace std;

int my_atoi(const char *str) {
	long long ret = 0;
	int max = 2147483647, min = 0-2147483648;
	if (str == NULL)
		return 0;
	int isn = 0;
	const char *p = str;
	while (*p == ' ') {p++;}
	if (*p == '-')	{p++; isn = 1;}
	else if (*p == '+') {p++; isn = 0;}

	while (*p != '\0' && *p >= '0' && *p <= '9') {
		ret = ret * 10 + *p - '0';
		if (ret > max) {
			if (isn)
				return ~max;
			else 
				return max;
		}
		else if (ret <= min) {
			if (isn)
				return ~min;
			else 
				return min;
		}
		p++;
	}
	
	int result = (int)ret;

	if (isn) result = ~result + 1;

	return result;
}


int main(void)
{



	char s[] = "  -   21474836470";

	
	cout << atoi(s) << endl;
	cout << my_atoi(s) << endl;

	return 0;
}

