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
		//����Ѱ��
		while (_cur)
		{
			if (cur->value < value)//�������ֵС�ڵ�ǰ����ֵ���ͽ����������ж�
			{
				parent = cur;//��֮ǰ����֮ǰ����Ϣ�������ҵ�ʱ��ǰһ�����β��
				cur = cur->_right	
			}
			else if (cur->value > value)//�������ֵ���ڵ�ǰ����ֵ���ͽ����������ж�
			{
				parent = cur;
				cur = cur->_left;
			}
			else//��ͬʱ
			{
				return false;
			}
		}
		//�����½ڵ�
		cur = new Node(value);//
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
private:
	Node* _root = nullptr;
};
