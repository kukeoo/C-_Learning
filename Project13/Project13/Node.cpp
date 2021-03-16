#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include "Tree.h"
using namespace std;

//链表的结构
typedef struct Node
{
	int data;
	Node* next;
}Node,*LinkedList;

//链表的头插法
LinkedList creatH()
{
	//创建头结点，为头结点分配空间
	Node* head = (Node*)malloc(sizeof(Node));
	//头结点的next域置空
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

//尾插法
LinkedList creatT()
{
	//创建头结点，为头结点分配空间
	Node* head = (Node*)malloc(sizeof(Node));
	//头结点的next域置空
	head->next = NULL;
	//创建当前指针cur;
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

//求长度
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

//插入结点
void insertList(LinkedList L,int loc,int val)
{
	if (loc <1 || loc> getLength(L))
	{
		cout << "插入范围有误！" << endl;
		return;
	}
	//指向头结点
	Node* cur = L;
	for (int i = 1; i < loc; i++)
	{
		cur = cur->next;
	}
	//创建结点
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = val;
	//插入结点
	p->next = cur->next;
	cur->next = p;
	cout << "插入成功！" << endl;
}

//删除结点
void deleteList(LinkedList& L, int loc)
{
	if (loc <1 || loc> getLength(L))
	{
		cout << "删除范围有误！" << endl;
		return;
	}
	//指向头结点
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

//单链表反转
LinkedList reverseList(LinkedList& L)
{
	Node* head = L;
	//指向当前结点
	Node* cur;
	//存放后续链表
	Node* nex;
	//新链表
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

//打印链表
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

//链表的释放
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