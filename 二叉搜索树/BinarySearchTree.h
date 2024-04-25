#pragma once
#include <iostream>
using namespace std;

//Kģ��
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

	//����Ѱ��
	while (cur)
	{
		if (cur->key < key)//��ǰ����ֵС�ڲ������ֵ���ͽ����������ж�
		{
			parent = cur;//��֮ǰ����֮ǰ����Ϣ�������ҵ�ʱ��ǰһ�����β��
			cur = cur->right;
		}
		else if (cur->key > key)//��ǰ����ֵ���ڲ������ֵ���ͽ����������ж�
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
	cur = new Node(key);

	if (parent->key < key)
	{
		parent->right = cur;
	}
	else
	{
		parent->left = cur;
	}
	return true;//�ɹ����뷵��true
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
		//����Ѱ�ҵ�Ҫɾ����ֵ
		else
		{
			//ɾ��������ڵ�Ϊ��
			if (cur->left == nullptr)
			{
				//ɾ������Ǹ��ڵ�
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

			//ɾ�������ҽڵ�Ϊ��
			else if (cur->right == nullptr)
			{
				//ɾ������Ǹ��ڵ�
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
			//ɾ���������ҽ�����Ϊ��
			else
			{
				//���������������������ɾ��
				Node* rightMinParent = cur;
				Node* rightMin = cur->right;
				//����Ѱ��
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
	//��һ�㣨��Ԫ����һ�㡢get���ַ�ʽ��ȡ���ڵ����ݣ�
	void InOrder()
	{
		_InOrder(root);
		cout << endl;
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
		//ѭ������
		for (auto e : a)
		{
			t1.Insert(e);
		}

		//�������
		t1.InOrder();

		//ɾ�����
		t1.erase(8);

		//�������
		t1.InOrder();
	}
}

//KVģ��
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

	//����Ѱ��
	while (cur)
	{
		if (cur->key < key)//��ǰ����ֵС�ڲ������ֵ���ͽ����������ж�
		{
			parent = cur;//��֮ǰ����֮ǰ����Ϣ�������ҵ�ʱ��ǰһ�����β��
			cur = cur->right;
		}
		else if (cur->key > key)//��ǰ����ֵ���ڲ������ֵ���ͽ����������ж�
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
	cur = new Node(key,value);

	if (parent->key < key)
	{
		parent->right = cur;
	}
	else
	{
		parent->left = cur;
	}
	return true;//�ɹ����뷵��true
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
		//����Ѱ�ҵ�Ҫɾ����ֵ
		else
		{
			//ɾ��������ڵ�Ϊ��
			if (cur->left == nullptr)
			{
				//ɾ������Ǹ��ڵ�
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

			//ɾ�������ҽڵ�Ϊ��
			else if (cur->right == nullptr)
			{
				//ɾ������Ǹ��ڵ�
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
			//ɾ���������ҽ�����Ϊ��
			else
			{
				//���������������������ɾ��
				Node* rightMinParent = cur;
				Node* rightMin = cur->right;
				//����Ѱ��
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
	//��һ�㣨��Ԫ����һ�㡢get���ַ�ʽ��ȡ���ڵ����ݣ�
	void InOrder()
	{
		_InOrder(root);
		cout << endl;
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
		cout << root->key << ":" <<root->_value<<endl;
		_InOrder(root->right);
	}

private:
	Node* root = nullptr;
};

	void test()
	{
		BSTree<string, string> dict;
		dict.Insert("string","�ַ���");
		dict.Insert("left", "���");
		dict.Insert("insert", "����");

		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);//Find�����ķ���ֵ��Ϊ�˽���ָ��
			if (ret)
			{
				cout << ret->_value << endl;
			}
			else
			{
				cout << "�޴˵��ʣ�����������" << endl;
			}
		}
	}

	void test1()
	{
		//ͳ�ƴ���
		string arr[] = { "ƻ��","����","�㽶","����","�㽶" ,"����","�㽶" ,"����","��ݮ" };
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