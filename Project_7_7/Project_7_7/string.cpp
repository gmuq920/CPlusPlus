#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

class string 
{
	string() 
		:array(nullptr),
		_size(0),
		_capacity(0)
	{}
	string(const string& other) 
	{
		_size = other._size;
		_capacity = other._capacity;

		if (other.array)
		{
			array = new char[_capacity];
			copy(other.array, other.array + _size, array);
		}
		else 
		{
			array = nullptr;
		}
	}
	string& operator=(const string& other) 
	{
		if (this == &other) return *this;  // 防止自赋值

		delete[] array; // 释放旧内存

		_size = other._size;
		_capacity = other._capacity;
		if (other.array) {
			array = new char[_capacity];
			std::copy(other.array, other.array + _size, array);
		}
		else {
			array = nullptr;
		}

		return *this; 
	}
	~string() 
	{
		delete[] array;
		array = nullptr;
		_size = 0;
		_capacity = 0;
	}
	const char& operator[](size_t  pos) const
	{
		assert(_size > pos);
		return array[pos];
	}

private:
	char* array;
	int _size;
	int _capacity;

};