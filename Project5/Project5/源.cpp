#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream ofs;

	ifstream ifs;
	ofs.open("C:\\Users\\asus\\Desktop\\readme.txt", ios::out);
	
	

	ofs.close();
	return 0;
}