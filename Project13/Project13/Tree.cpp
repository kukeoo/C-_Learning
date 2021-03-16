#define _CRT_SECURE_NO_WARNINGS 1

#include "Tree.h"

Tree createTree()
{
	int value;
	cin >> value;
	if (value == -1)
	{
		return NULL;
	}
	BNode* n = (BNode*)malloc(sizeof(BNode));
	n->data = value;
	n->left = createTree();
	n->right = createTree();
	return n;
}

void insertBST(Tree& t,int value)
{
	BNode* node = (BNode*)malloc(sizeof(BNode));
	node->data = value;
	node->left = NULL;
	node->right = NULL;

	if (t == NULL)
	{
		t = node;
	}
	else
	{
		BNode* temp = t;
		while (temp != NULL)
		{
			//����������
			if(value<temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = node;
					return;
				}
				temp = temp->left;
			}

			//����������
			if (value > temp->data)
			{
				if (temp->right == NULL)
				{
					temp->right = node;
					return;
				}
				temp = temp->right;
			}
		}
	}
}

//ǰ�����
void preOrder(Tree t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		preOrder(t->left);
		preOrder(t->right);
	}
}

//�������
void inOrder(Tree t)
{
	if (t != NULL)
	{
		inOrder(t->left);
		cout << t->data << " ";
		inOrder(t->right);
	}
}

//�������
void postOrder(Tree t)
{
	if (t != NULL)
	{
		postOrder(t->left);
		postOrder(t->right);
		cout << t->data << " ";
	}
}

//���ظ߶�
int getLength(Tree t)
{
	if (t == NULL)
	{
		return 0;
	}
	int thisLength = 1;
	int leftLength = getLength(t->left);
	int rightLength = getLength(t->right);
	int maxLRLength = leftLength > rightLength ? leftLength : rightLength;
	int length = thisLength + maxLRLength;
	return length;
}

//�������
//����������һ�����������һ�����У�һ����ǰ������
void levelOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	//����������������Ų���������
	vector<int> result;
	//�ö��д洢���
	queue<BNode*> q;
	//��������
	q.push(t);
	//ֻҪ��ǰ���в�Ϊ��
	while (!q.empty())
	{
		//���ڴ洢��ǰ������һ��Ľ��
		vector<int> temp;
		int n = q.size();
		for (int i = 0; i < n; i++)
		{
			BNode* cur = q.front();
			temp.push_back(cur->data);
			q.pop();
			if (cur->left != NULL)
			{
				q.push(cur->left);
			}
			if (cur->right != NULL)
			{
				q.push(cur->right);
			}
		}
		for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
		{
			result.push_back(*it);
		}
	}
	for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
	{
		cout << *it << " ";
	}
}

//�ؽ�������
Tree reBuild(vector<BNode*>pre, vector<BNode*>vin)
{
	int vinlen = vin.size();
	if (vinlen == 0)
	{
		return NULL;
	}
	vector<Tree>leftPre, leftVin,rightPre,rightVin;
	BNode* root = (BNode*)malloc(sizeof(BNode));
	root->data = pre[0]->data;
	int rootLocation = 0;
	for (int i = 0; i < vinlen; i++)
	{
		if (vin[i]->data == pre[0]->data)
		{
			rootLocation = i;
			break;
		}
	}
	for (int i = 0; i < rootLocation; i++)
	{
		leftPre.push_back(pre[i + 1]);
		leftVin.push_back(vin[i]);
	}
	for (int i = rootLocation + 1; i < vinlen; i++)
	{
		rightPre.push_back(pre[i]);
		rightVin.push_back(vin[i]);
	}
	root->left = reBuild(leftPre, leftVin);
	root->right = reBuild(rightPre, rightVin);
	return root;
}