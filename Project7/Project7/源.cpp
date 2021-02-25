#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>

using namespace std;

//����ģ��
//�������ͽ�������
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//���������ͽ�������
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ��
template<typename T>//����һ��ģ��
//typename�����滻��class
//���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ����������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySelectSort(T array[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (array[max] < array[j])
			{
				max = j;
			}
		}
		if (array[i] != array[max])
		{
			mySwap<int>(array[i], array[max]);
		}
		cout << "���ǵ�" << i + 1 << "������" << endl;
	}
}

template<typename T>
void myBubbleSort(T array[], int len)
{
	
	for (int i = 0; i < len - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				mySwap<int>(array[j], array[j + 1]);
				flag = true;
			}
		}
		cout << "���ǵ�" << i + 1 << "������" << endl;
		if (flag == false)
		{
			return;
		}
	}
}

template<typename T>
int myBinarySearch(T array[], int len, int x)
{
	T low = 0;
	T high = len - 1;

	while (low <= high)
	{
		T mid = (low + high) / 2;
		if (x < array[mid])
		{
			high = mid - 1;
		}
		else if (x > array[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return low;
}

template<typename T>
void myInsertSort(T array[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int j = i;
		T temp = array[i];
		int num = 0;
		while (j)
		{
			if (temp < array[j - 1])
			{
				array[j] = array[j - 1];
				j--;
				num++;
				cout << "���ǵ�" << i << "�������еĵ�"<<num<<"��Ųλ" << endl;
			}
			else
			{
				break;
			}
		}
		array[j] = temp;
		cout << "���ǵ�" << i << "������" << endl;
	}
}

template<typename T>
void myBinaryInsertSort(T array[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int j = i;
		T temp = array[j];
		int num = 0;
		int down = myBinarySearch(array, j, temp);
		cout << "Ԫ��" << temp << "Ӧ�÷��ڱ����������еĵ�" << down + 1 << "��λ��" << endl;
		while (j > down)
		{
			array[j] = array[j - 1];
			j--;
		}
		array[down] = temp;
		cout << "���ǵ�" << i << "������" << endl;
	}
}

template<typename T>
void myShellSort(T array[], int len)
{
	int d = 0;//��ʼ������
	for (int d = len / 2; d >= 1; d /= 2)
	{
		for (int i = d; i < len; i++ )
		{
			T temp = array[i];
			int j;
			for (j = i; j >= d && temp < array[j - d]; j -= d)
			{
				array[j] = array[j - d];
			}
			array[j] = temp;
		}
	}
}

int main()
{
	//int a = 20;
	//int b = 10;
	////��һ�� �Զ������Ƶ�
	////mySwap(a, b);
	////�ڶ��� ��ʾָ������
	//mySwap<int>(a, b);
	//cout << a << endl;
	//cout << b << endl;
	int b[] = {5,21,6,8,4,3,2,1};
	int len = sizeof(b) / sizeof(b[0]);
	cout << len << endl;
	//cout << myBinarySearch<int>(b, len, 2);
	myBinaryInsertSort<int>(b, len);
	for (int i = 0; i < len; i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}