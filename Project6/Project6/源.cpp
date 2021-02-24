#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Person
{
public:
	mutable int m_age;
	static int tall;

public:
	Person()
	{

	}

	Person(int age)
	{
		m_age = age;
	}

	Person(const Person& p)
	{
		m_age = p.m_age;
	}

	static void func()
	{
		cout << "static func!" << endl;
	}

	Person& PersonAddPerson(Person p)
	{
		this->m_age += p.m_age;
		//返回对象本身
		return *this;
	}

	void show() const
	{
		this->m_age = 100;
	}

	Person& operator++()
	{
		this->m_age++;
		return *this;
	}

	Person& operator++(int)
	{
		Person temp = *this;
		this->m_age++;
		return temp;
	}

};
int Person::tall = 10;



class Animal
{
public:
	int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;

	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}
int main()
{
	//Person p1;
	//p1.m_age = 1;
	//Person p2;
	//p2 = p1;
	//cout << (++p1).m_age;
	//cout << p1.m_age;
	test01();
	return 0;
}