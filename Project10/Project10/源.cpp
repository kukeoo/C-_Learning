#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int getLength(string s)
{
	int length = 0;
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		length++;
	}
	return length;
}

int main()
{
	string src = { 0 };
	while (getline(cin, src))
	{
		int length = getLength(src);
		int number = count(src.begin(), src.end(), ' ');
		string::iterator s = src.begin();
		int loc = 0;
		while (number)
		{
			s++;
			loc++;
			if (*s == ' ')
			{
				number--;
			}
		}
		loc++;
		int rest = length - loc;
		string dest = src.substr(loc, rest);
		cout << dest;
		const char* p;
		p = (const char*)dest;
		int ans = strlen((const char*)dest);
	}
	return 0;
}