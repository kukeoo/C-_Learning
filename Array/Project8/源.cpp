#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "MyArray.hpp"
using namespace std;

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	MyArray<int>arr1(5);

	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	arr1.Pop_Back(4);
	cout << "arr1的打印输出为："<< endl;
	printIntArray(arr1);
}

class Person
{
public:
	string m_Name;
	int m_Age;

public:
	Person() {};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Age << endl;
		cout << "年龄：" << arr[i].m_Name << endl;
	}
}

void test02()
{
	MyArray<Person> arr(10);
	Person p1("kk", 99);
	Person p2("aa", 21);
	Person p3("ww", 22);
	Person p4("ee", 23);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);

	printPersonArray(arr);
}
int main()
{
	test02();
	return 0;
}