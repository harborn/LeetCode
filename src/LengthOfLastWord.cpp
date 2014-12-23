


int lengthOfLastWord(const char *s) {
	const char *p = s;
	const char *p2 = s;
	while (*p == ' ') p++;
	while (*p2 != '\0')p2++;
	p2--;
	while (*p2 == ' ')p2--;
	int l = 0;
	while (*p2 != ' ' && p2 >= p) {
		p2--; l++;
	}
	//if (p2 >= p)
	//	return l;
	//return 0;
	return l;
}

int main(void)
{
	char *p = "aaf  abdaf  dfadff eeeeeeee";

	int ret = lengthOfLastWord(p);

	
	return 0;
}