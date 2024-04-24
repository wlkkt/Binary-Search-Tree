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

		//遍历寻找
		while (cur)
		{
			if (cur->value < value)//当前结点的值小于插入结点的值，就进入右子树判断
			{
				parent = cur;//走之前保留之前的信息，便于找到时向前一个结点尾插
				cur = cur->right;
			}
			else if (cur->value > value)//当前结点的值大于插入结点的值，就进入左子树判断
			{
				parent = cur;
				cur = cur->left;
			}
			else//相同时
			{
				return false;
			}
		}
		//插入新节点
		cur = new Node(value);

		if (parent->value < value)
		{
			parent->right = cur;
		}
		else
		{
			parent->left = cur;
		}
		return true;//成功插入返回true
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

	//套一层（友元、套一层、get三种方式获取类内的数据）
	void InOrder()
	{
		_InOrder(root);
	}

private:

	//循环遍历
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
	//循环插入
	for (auto e : a)
	{
		t1.Insert(e);
	}

	//中序遍历
	t1.InOrder();
}

