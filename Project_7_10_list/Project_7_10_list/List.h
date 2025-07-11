#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
struct list_node
{
	list_node(const T& val = T()) 
		:_data(val),
		_next(nullptr),
		_prev(nullptr)
	{}
	T _data;
	list_node<T>* _next;
	list_node<T>* _prev;
};

template<class T>
struct list_iterator
{
	typedef list_node<T> Node;
	typedef list_iterator<T> Self;
	Node* _node;

	list_iterator(Node* node) 
		:_node(node)
	{}
	T& operator*() 
	{
		return _node->_data;
	}

	Self& operator++() 
	{
		_node = _node->_next;
		return *this;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	

};

template<class T>
class list
{
	typedef list_node<T> Node;
public:

	typedef list_iterator<T>iterator;

	iterator begin() 
	{
		return iterator(_head->_next);
	}

	iterator end() 
	{
		return _head;
	}


	list()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		_size = 0;
	}

	void push_back(const T& val) 
	{
		Node* tmp = new Node(val);
		tmp->_next = _head;
		tmp->_prev = _head->_prev;
		_head->_prev->_next = tmp;
		_head->_prev = tmp;
		_size++;
	}

	void insert(iterator pos, const T& x)
	{
		Node* newNode = new Node(x);
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		prev->_next = newNode;
		newNode->_next = cur;
		cur->_prev = newNode;
		newNode->_prev = prev;
		_size++;
	}

	size_t size()
	{
		return _size;
	}


	void Print() 
	{
		Node* cur = _head->_next;
		while (cur != _head) 
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}

	void erase(iterator pos) 
	{
		assert(pos != end());

		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;
		prev->_next = next;
		next->_prev = prev;
		delete cur;
		_size--;
	}

	void pop_back() 
	{
		erase(--end());
	}

	void pop_front() 
	{
		erase(begin());
	}

	Node* find(const T& x) 
	{
		Node* cur = _head->_next;
		while (cur->_data != x && cur!=_head )
		{
			cur = cur->_next;
		}
		return cur;
	}
private:
	Node* _head;
	size_t _size;
};


void test01() 
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	lt.insert(lt.begin(), 100);

	list<int>::iterator it = lt.begin();
	while (it != lt.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << lt.size()<<endl;

	lt.erase(lt.find(100));

	lt.Print();
	
}