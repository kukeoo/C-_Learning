//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int getLength(string s)
//{
//	int length = 0;
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		it++;
//		length++;
//	}
//	return length;
//}
//
//bool cmp(string ret)
//{
//	if (ret[0] == ret[1] && ret[1] == ret[2])
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	string a;
//	cin >> a;
//	//大循环
//	while (1)
//	{
//		int length = getLength(a);
//		if (length < 3)
//		{
//			if (length == 0)
//			{
//				cout << '0';
//				break;
//			}
//			else
//			{
//				cout << a;
//				break;
//			}
//		}
//		string::iterator it = a.begin();
//		//定义一个从起始位置到截取字符串的差
//		int gap = 0;
//		for (string::iterator it = a.begin(); it != a.end(); it++)
//		{
//			//小循环
//			//临时字符串，用来存放判断是否消除的字符组
//			string ret;
//			int count = 0;
//			string::iterator s = it;
//			while (s != a.end())
//			{
//				ret += *s;
//				count++;
//				s++;
//				//如果满足需要判断的条件，则出来
//				if (count % 3 == 0)
//				{
//					break;
//				}
//			}
//			int rest = length - gap - count;
//			if (cmp(ret) == true)
//			{
//				string s1 = a.substr(0, gap);
//				string s2 = a.substr(gap + 3, rest);
//				a = s1 + s2;
//				break;
//			}
//			gap++;
//		}
//	}
//	return 0;
//}