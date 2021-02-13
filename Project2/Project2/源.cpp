#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Person
{
public:
	int age;

public:

	Person()
	{

	}


	Person(int age) 
	{
		this->age = age;
	}

};

Person& BiggerPerson(Person& p1,Person& p2)
{
	if (p1.age > p2.age)
	{
		p1.age++;
		return p1;
	}

	else
	{
		p2.age++;
		return p2;
	}
}

int main()
{
	Person p1(5);
	Person p2(10);
	cout << BiggerPerson(p1,p2).age<< endl;

	return 0;
}