#include<iostream>


using namespace std;


template<class K>
struct BSTreeNode 
{
	K _key;
	BSTreeNode* _right;
	BSTreeNode* _left;

	BSTreeNode(K key) {
		_key = key;
		_right = nullptr;
		_left = nullptr;
	}
};

template<class K>
class BSTree
{
	using Node = BSTreeNode<K>;
public:
	bool Insert(const K& key)
	{
		if (!_root) 
		{
			_root = new Node(key);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) 
		{
			if (cur->_key < key) 
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else 
			{
				return false;
			}
		}
		if (parent->_key > key) 
		{
			parent->_left = new Node(key);
			return true;
		}
		else
		{
			parent->_right = new Node(key);
			return true;
		}
	}

	void InOrder() 
	{
		_InOrder(_root);
		cout << endl;
	}

	
private:
	Node* _root = nullptr;
	void _InOrder(Node* _root) 
	{
		if (_root == nullptr) {
			return;
		}
		_InOrder(_root->_left);
		cout << _root->_key << " ";
		_InOrder(_root->_right);
	}
};