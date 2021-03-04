#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <ctime>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;


class MyCompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};

void print01(int val)
{
	cout << val << " ";
}

class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class transform1
{
public:
	int operator()(int v)
	{
		return v;
	}
};

class Person
{
public:
	string name;
	int age;
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	bool operator==(const Person& p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		else
		{
			return false;
		}
			
	}
};

class AgeGreater
{
public:
	bool operator()(Person& p1)
	{
		return p1.age>4;
	}
};

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class great
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	srand((unsigned int)time(NULL));
	vector<Person> v;
	Person p1("a", 5);
	Person p2("b", 6);
	Person p3("c", 6);
	Person p4("d", 8);
	Person p5("e", 9);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(7);
	v2.push_back(9);
	v2.push_back(10);
	vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(8);
	v3.push_back(13);
	v3.push_back(15);
	vector<int> tar;
	tar.resize(max(v2.size(),v3.size()));
	vector<int>::iterator itEnd = set_difference(v2.begin(),v2.end(), v3.begin(), v3.end(),tar.begin() );
	
	for_each(tar.begin(), itEnd, MyPrint());
} 
int main()
{
	test01();
	return 0;
}