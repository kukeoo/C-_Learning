#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include "Tree.h"
using namespace std;

//����Ľṹ
typedef struct Node
{
	int data;
	Node* next;
}Node,*LinkedList;

//�����ͷ�巨
LinkedList creatH()
{
	//����ͷ��㣬Ϊͷ������ռ�
	Node* head = (Node*)malloc(sizeof(Node));
	//ͷ����next���ÿ�
	head->next = NULL;

	int value;
	while (cin >> value)
	{
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = value;
		p->next = head->next;
		head->next = p;
	}
	return head;
}

//β�巨
LinkedList creatT()
{
	//����ͷ��㣬Ϊͷ������ռ�
	Node* head = (Node*)malloc(sizeof(Node));
	//ͷ����next���ÿ�
	head->next = NULL;
	//������ǰָ��cur;
	Node* cur = head;

	int value;
	while (cin >> value)
	{
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = value;
		p->next = cur->next;
		cur->next = p;
		cur = p;
	}
	return head;
}

//�󳤶�
int getLength(LinkedList L)
{
	int length = 0;
	Node* cur = L->next;
	while (cur != NULL)
	{
		length++;
		cur = cur->next;
	}
	return length;
}

//������
void insertList(LinkedList L,int loc,int val)
{
	if (loc <1 || loc> getLength(L))
	{
		cout << "���뷶Χ����" << endl;
		return;
	}
	//ָ��ͷ���
	Node* cur = L;
	for (int i = 1; i < loc; i++)
	{
		cur = cur->next;
	}
	//�������
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = val;
	//������
	p->next = cur->next;
	cur->next = p;
	cout << "����ɹ���" << endl;
}

//ɾ�����
void deleteList(LinkedList& L, int loc)
{
	if (loc <1 || loc> getLength(L))
	{
		cout << "ɾ����Χ����" << endl;
		return;
	}
	//ָ��ͷ���
	Node* cur = L;
	for (int i = 1; i < loc; i++)
	{
		cur = cur->next;
	}
	Node* del = cur->next;
	cur->next = del->next;
	free(del);
	del = NULL;
}

//������ת
LinkedList reverseList(LinkedList& L)
{
	Node* head = L;
	//ָ��ǰ���
	Node* cur;
	//��ź�������
	Node* nex;
	//������
	Node* pre = NULL;
	cur = L->next;
	free(head);
	head = NULL;
	while (cur != NULL)
	{
		nex = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nex;
	}
	Node* newHead = (Node*)malloc(sizeof(Node));
	newHead->next = pre;
	return newHead;
}

//��ӡ����
void printList(LinkedList L)
{
	Node* cur = L->next;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

//������ͷ�
void releaseList(LinkedList L)
{
	Node* cur = L;
	Node* nex = L;
	while (cur)
	{
		nex = nex->next;
		free(cur);
		cur->next = NULL;
		cur = nex;
	}
}

void test01()
{

}

int main()
{
	//LinkedList L = creatT();
	//L = reverseList(L);
	//insertList(L, 1, 6);
	//printList(L);
	//releaseList(L);
	//Tree root = NULL;
	//insertBST(root, 5);
	//insertBST(root, 7);
	//insertBST(root, 1);
	//insertBST(root, 2);
	//insertBST(root, 6);
	//insertBST(root, 8);
	//cout << endl;
	//cout << getLength(root);

	return 0;
}