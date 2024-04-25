#pragma once
#include <iostream>
using namespace std;

//K模型
namespace key
{
template<class K>
struct  BSTreeNode
{
	BSTreeNode<K>* left;
	BSTreeNode<K>* right;
	K key;

	BSTreeNode(const K& key)
		:left(nullptr)
		, right(nullptr)
		, key(key)
	{}
};


template<class K>
class  BSTree
{
	typedef BSTreeNode<K> Node;
public:
bool Insert(const K& key)
{
	if (root == nullptr)
	{
		root = new Node(key);
		return true;
	}

	Node* parent = nullptr;
	Node* cur = root;

	//遍历寻找
	while (cur)
	{
		if (cur->key < key)//当前结点的值小于插入结点的值，就进入右子树判断
		{
			parent = cur;//走之前保留之前的信息，便于找到时向前一个结点尾插
			cur = cur->right;
		}
		else if (cur->key > key)//当前结点的值大于插入结点的值，就进入左子树判断
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
	cur = new Node(key);

	if (parent->key < key)
	{
		parent->right = cur;
	}
	else
	{
		parent->left = cur;
	}
	return true;//成功插入返回true
}

bool Find(const K& key)
{
	Node* cur = root;
	while (cur)
	{
		if (cur->key < key)
		{
			cur = cur->right;
		}
		else if (cur->key > key)
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

bool erase(const K& key)
{
	Node* parent = nullptr;
	Node* cur = root;
	while (cur)
	{
		if (cur->key < key)
		{
			cur = cur->right;
		}
		else if (cur->key > key)
		{
			cur = cur->left;
		}
		//遍历寻找到要删除的值
		else
		{
			//删除结点的左节点为空
			if (cur->left == nullptr)
			{
				//删除结点是根节点
				if (cur == root)
				{
					root = cur->right;
				}
				else
				{
					if (cur == parent->left)
					{
						parent->left = cur->right;
					}
					else
					{
						parent->right = cur->left;
					}
				}
				delete cur;
			}

			//删除结点的右节点为空
			else if (cur->right == nullptr)
			{
				//删除结点是根节点
				if (cur == root)
				{
					root = cur->left;
				}
				else
				{
					if (cur == parent->left)
					{
						parent->left = cur->left;
					}
					else
					{
						parent->right = cur->left;
					}
				}
				delete cur;
			}
			//删除结点的左右结点均不为空
			else
			{
				//查找右子树的最左结点替代删除
				Node* rightMinParent = cur;
				Node* rightMin = cur->right;
				//遍历寻找
				while (rightMin->left)
				{
					rightMinParent = rightMin;
					rightMin = rightMin->left;
				}

				swap(cur->key, rightMin->key);

				if (rightMinParent->left == rightMin)
					rightMinParent->left = rightMin->right;
				else
					rightMinParent->right = rightMin->right;
				delete rightMin;
			}
			return true;
		}
	}
	return false;
}

public:
	//套一层（友元、套一层、get三种方式获取类内的数据）
	void InOrder()
	{
		_InOrder(root);
		cout << endl;
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
		cout << root->key << " ";
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

		//删除结点
		t1.erase(8);

		//中序遍历
		t1.InOrder();
	}
}

//KV模型
namespace key_value
{
template<class K,class V>
struct  BSTreeNode
{
	BSTreeNode<K,V>* left;
	BSTreeNode<K,V>* right;
	K key;
	V _value;

	BSTreeNode(const K& key,const V& value)
		:left(nullptr)
		,right(nullptr)
		,key(key)
		,_value(value)
	{}
};


template<class K,class V>
class  BSTree
{
	typedef BSTreeNode<K,V> Node;
public:
bool Insert(const K& key,const V& value)
{
	if (root == nullptr)
	{
		root = new Node(key,value);
		return true;
	}

	Node* parent = nullptr;
	Node* cur = root;

	//遍历寻找
	while (cur)
	{
		if (cur->key < key)//当前结点的值小于插入结点的值，就进入右子树判断
		{
			parent = cur;//走之前保留之前的信息，便于找到时向前一个结点尾插
			cur = cur->right;
		}
		else if (cur->key > key)//当前结点的值大于插入结点的值，就进入左子树判断
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
	cur = new Node(key,value);

	if (parent->key < key)
	{
		parent->right = cur;
	}
	else
	{
		parent->left = cur;
	}
	return true;//成功插入返回true
}

Node* Find(const K& key)
{
	Node* cur = root;
	while (cur)
	{
		if (cur->key < key)
		{
			cur = cur->right;
		}
		else if (cur->key > key)
		{
			cur = cur->left;
		}
		else
		{
			return cur;
		}
	}
	return cur;
}

bool erase(const K& key)
{
	Node* parent = nullptr;
	Node* cur = root;
	while (cur)
	{
		if (cur->key < key)
		{
			cur = cur->right;
		}
		else if (cur->key > key)
		{
			cur = cur->left;
		}
		//遍历寻找到要删除的值
		else
		{
			//删除结点的左节点为空
			if (cur->left == nullptr)
			{
				//删除结点是根节点
				if (cur == root)
				{
					root = cur->right;
				}
				else
				{
					if (cur == parent->left)
					{
						parent->left = cur->right;
					}
					else
					{
						parent->right = cur->left;
					}
				}
				delete cur;
			}

			//删除结点的右节点为空
			else if (cur->right == nullptr)
			{
				//删除结点是根节点
				if (cur == root)
				{
					root = cur->left;
				}
				else
				{
					if (cur == parent->left)
					{
						parent->left = cur->left;
					}
					else
					{
						parent->right = cur->left;
					}
				}
				delete cur;
			}
			//删除结点的左右结点均不为空
			else
			{
				//查找右子树的最左结点替代删除
				Node* rightMinParent = cur;
				Node* rightMin = cur->right;
				//遍历寻找
				while (rightMin->left)
				{
					rightMinParent = rightMin;
					rightMin = rightMin->left;
				}

				swap(cur->key, rightMin->key);
				if (rightMinParent->left == rightMin)
					rightMinParent->left = rightMin->right;
				else
					rightMinParent->right = rightMin->right;
				delete rightMin;
			}
			return true;
		}
	}
	return false;
}

public:
	//套一层（友元、套一层、get三种方式获取类内的数据）
	void InOrder()
	{
		_InOrder(root);
		cout << endl;
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
		cout << root->key << ":" <<root->_value<<endl;
		_InOrder(root->right);
	}

private:
	Node* root = nullptr;
};

	void test()
	{
		BSTree<string, string> dict;
		dict.Insert("string","字符串");
		dict.Insert("left", "左边");
		dict.Insert("insert", "插入");

		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);//Find函数的返回值变为了结点的指针
			if (ret)
			{
				cout << ret->_value << endl;
			}
			else
			{
				cout << "无此单词，请重新输入" << endl;
			}
		}
	}

	void test1()
	{
		//统计次数
		string arr[] = { "苹果","西瓜","香蕉","西瓜","香蕉" ,"西瓜","香蕉" ,"西瓜","草莓" };
		BSTree<string, int> countTree;
		for (const auto& str : arr)
		{
			auto ret = countTree.Find(str);
			if (ret == nullptr)
			{
				countTree.Insert(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}
		countTree.InOrder();
	
	}
}