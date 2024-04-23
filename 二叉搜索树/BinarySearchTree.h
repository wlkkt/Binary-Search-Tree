#pragma once

template<class T>
struct  BSTreeNode
{

};


template<class T>
struct  BSTree
{
	typedef BSTreeNode<T> Node;
public:
	bool Insert(const T& value)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		//遍历寻找
		while (_cur)
		{
			if (cur->value < value)//插入结点的值小于当前结点的值，就进入左子树判断
			{
				parent = cur;//走之前保留之前的信息，便于找到时向前一个结点尾插
				cur = cur->_right	
			}
			else if (cur->value > value)//插入结点的值大于当前结点的值，就进入右子树判断
			{
				parent = cur;
				cur = cur->_left;
			}
			else//相同时
			{
				return false;
			}
		}
		//插入新节点
		cur = new Node(value);//
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
private:
	Node* _root = nullptr;
};
