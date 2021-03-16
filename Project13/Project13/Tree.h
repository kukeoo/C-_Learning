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

//创建二叉树
Tree createTree();
//插入，成为二叉搜索树
void insertBST(Tree& t, int value);
//先序遍历
void preOrder(Tree t);
//中序遍历
void inOrder(Tree t);
//后序遍历
void postOrder(Tree t);
//返回高度
int getLength(Tree t);
//层序遍历
void levelOrder(Tree t);
//重建二叉树
Tree reBuild(vector<BNode*>pre, vector<BNode*>vin);
