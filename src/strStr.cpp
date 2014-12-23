

#include <iostream>

char *strStr(char *haystack, char *needle) {
	int len1 = 0, len2 = 0;
	char *p1 = haystack, *p2 = needle;
	while (*p1++ != '\0') len1++;
	while (*p2++ != '\0') len2++;
	if (len2 == 0) return haystack;
	if (len2 > len1) return "";
	

	int l1 = len1;
	
	p1 = haystack;
	while (l1 >= len2) {
		int j = 0; int ll = len2;
		while (j < ll) {
			if (p1[j] != needle[j])
				break;
			j++;
		}
		if (j && j == ll) {
			return p1;
		}

		p1++;
		l1--;
	}
	return NULL;
}

int main(void)
{
	char *p1 = "a";
	char *p2 = "a";
	char *res = strStr(p1, p2);


	return 0;
}
