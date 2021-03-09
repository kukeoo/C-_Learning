#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getLength(string s)
{
	int length = 0;
	string::iterator it = s.begin();
	while (it != s.end())
	{
		it++;
		length++;
	}
	return length;
}

//��ʱ�����ж�
bool judgeRest(string ret)
{
	int length = getLength(ret);
	if (length >= 3)
	{
		//���е�������ֵ��ͬ�����ǿ������ġ�Ψһtrue����
		if (ret[length - 1] == ret[length - 2] && ret[length - 2] == ret[length - 3])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//�������ж�
int judgeString(string s)
{
	string ret;
	int length = getLength(s);
	//��ǰԪ�ص��±�
	int location = 0;
	bool flag = false;
	for (int i = 0; i < length; i++)
	{
		flag = false;
		ret += s[i];
		location++;
		if (judgeRest(ret))
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		//�����и����
		return location - 3;
	}
	else
	{
		return -1;
	}
}

int main()
{
	string a;
	cin >> a;
	while (judgeString(a) != -1)
	{
		int length = getLength(a);
		int location = judgeString(a);
		string front = a.substr(0, location);
		string back = a.substr(location + 3);
		a = front + back;
	}
	if (getLength(a) == 0)
	{
		cout << '0';
	}
	else
	{
		cout << a;
	}
	return 0;
}