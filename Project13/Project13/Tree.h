#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef struct BNode
{
	int data;
	BNode* left;
	BNode* right;
}BNode,*Tree;

//����������
Tree createTree();
//���룬��Ϊ����������
void insertBST(Tree& t, int value);
//�������
void preOrder(Tree t);
//�������
void inOrder(Tree t);
//�������
void postOrder(Tree t);
//���ظ߶�
int getLength(Tree t);
//�������
void levelOrder(Tree t);
//�ؽ�������
Tree reBuild(vector<BNode*>pre, vector<BNode*>vin);
