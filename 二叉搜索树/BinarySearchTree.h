#pragma once
#include <iostream>
using namespace std;

template<class T>
struct  BSTreeNode
{
	BSTreeNode<T>* left;
	BSTreeNode<T>* right;
	T value;

	BSTreeNode(const T& value)
		:left(nullptr)
		,right(nullptr)
		,value(value)
	{}
};


template<class T>
class  BSTree
{
	typedef BSTreeNode<T> Node;
public:
	bool Insert(const T& value)
	{
		if (root == nullptr)
		{
			root = new Node(value);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = root;

		//����Ѱ��
		while (cur)
		{
			if (cur->value < value)//��ǰ����ֵС�ڲ������ֵ���ͽ����������ж�
			{
				parent = cur;//��֮ǰ����֮ǰ����Ϣ�������ҵ�ʱ��ǰһ�����β��
				cur = cur->right;
			}
			else if (cur->value > value)//��ǰ����ֵ���ڲ������ֵ���ͽ����������ж�
			{
				parent = cur;
				cur = cur->left;
			}
			else//��ͬʱ
			{
				return false;
			}
		}
		//�����½ڵ�
		cur = new Node(value);

		if (parent->value < value)
		{
			parent->right = cur;
		}
		else
		{
			parent->left = cur;
		}
		return true;//�ɹ����뷵��true
	}

	bool Find(const T& value)
	{
		Node* cur = root;
		while (cur)
		{
			if (cur->value < value)
			{
				cur = cur->right;
			}
			else if (cur->value > value)
			{
				cur = cur->left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	//��һ�㣨��Ԫ����һ�㡢get���ַ�ʽ��ȡ���ڵ����ݣ�
	void InOrder()
	{
		_InOrder(root);
	}

private:

	//ѭ������
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		} 

		_InOrder(root->left);
		cout << root->value << " ";
		_InOrder(root->right);
	}

private:
	Node* root = nullptr;
};

void test()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	BSTree<int> t1;
	//ѭ������
	for (auto e : a)
	{
		t1.Insert(e);
	}

	//�������
	t1.InOrder();
}

