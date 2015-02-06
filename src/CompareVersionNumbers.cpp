
#include <iostream>
#include <string>

using namespace std;
//
//Compare two version numbers version1 and version1.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non-empty and contain only digits and the . character.
//The . character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.


int compareVersion(string version1, string version2) {
	int v1i = 0, v1j = 0;
	int v2i = 0, v2j = 0;
	int v1 = 0, v2 = 0;
	while (v1i < version1.size() || v2i < version2.size()) {
		while (v1i < version1.size() && (version1[v1i] == ' ' || version1[v1i] == '.')) v1i++;
		while (v2i < version2.size() && (version2[v2i] == ' ' || version2[v2i] == '.')) v2i++;
		v1j = v1i;
		v2j = v2i;
		while (v1j < version1.size() && version1[v1j] >= '0' && version1[v1j] <= '9') v1j++;
		while (v2j < version2.size() && version2[v2j] >= '0' && version2[v2j] <= '9') v2j++;
		if (v1i < v1j) v1 = std::stoi(version1.substr(v1i, v1j - v1i));
		else v1 = 0;
		if (v2i < v2j) v2 = std::stoi(version2.substr(v2i, v2j - v2i));
		else v2 = 0;
		v1i = v1j;
		v2i = v2j;
		if (v1 < v2) return -1;
		else if (v1 > v2) return 1;
	}

	return 0;
}

int compareVersion2(string version1, string version2) {

	version1.push_back('.');
	version2.push_back('.');

	while( !(version1.empty() && version2.empty()) )
	{
		size_t idx1 = 0;
		size_t idx2 = 0;

		int v1 = version1.empty() ? 0 : stoi(version1, &idx1);
		int v2 = version2.empty() ? 0 : stoi(version2, &idx2);

		version1.erase(0, idx1+1);
		version2.erase(0, idx2+1);

		if (v1 > v2)
		{
			return 1;
		}
		else if (v1 < v2)
		{
			return -1;
		}
	}

	return 0;
}


int main(void)
{
	string version1 = "1.000.0";
	string version2 = "1";

	int res = compareVersion(version1, version2);

	return 0;
}