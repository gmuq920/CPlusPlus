#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

namespace GMuQ
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector() 
		{}

		vector(const vector<T>& v) 
		{
			for (auto& e : v) {
				push_back(e);
			}
		}

		~vector()
		{
			if (_start) 
			{
				delete[]_start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector<T>& operator=(vector<T> v) 
		{
			swap(v);
			return *this;
		}

		iterator begin() {
			return _start;
		}
		
		iterator end() {
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				memcpy(tmp, _start, size() * sizeof(T));
				size_t nums = size();
				delete[] _start;
				_start = tmp;
				_finish = _start + nums;
				_end_of_storage = _start + n;
			}
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity() {
			return _end_of_storage - _start;
		}

		bool empty() {
			return begin() == end();
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			_finish++;
		}

		void pop_back() 
		{
			assert(!empty());
			_finish--;
		}

		void insert(iterator pos, const T& x) 
		{
			assert(begin() <= pos && end() > pos);
			int tmp = pos - _start;
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			iterator end = _finish;
			while (end >= (begin() + tmp))
			{
				*(end+1)= *end ;
				end--;
			}
			*(begin() + tmp) = x;
			++_finish;
		}

		auto operator[](size_t i)
		{
			assert(i < size());
			return *_start + i;
		}

		void print()
		{
			vector<T>::iterator it = begin();
			while (it != end()) {
				cout << *it << " ";
				it++;
			}
			cout << endl;
		}

		void erase(iterator pos) 
		{
			assert(begin() <= pos && end() > pos);
			vector<T>::iterator it = pos;
			while (it != end()-1) 
			{
				*it = *(it + 1);
				it++;
			}
			_finish--;
		}

		void resize(size_t n, T val = T())
		{
			if (size() > n)
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n) 
				{
					*_finish = val;
					_finish++;
				}
			}
			
		}

		
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};
	template<class T>
	void print_vector(const vector<T>& v)
	{
		typename vector<T>::const_iterator it = v.begin();
		while (it != v.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;

	}

	void test1() 
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		for (int i = 0;i < v.size();i++) 
		{
			cout << v[i] << " ";
		}
		cout << endl;
		print_vector(v);
		v.insert(v.begin()+1, 9);
		v.print();
		v.erase(v.begin() + 1);
		v.print();
		v.erase(v.begin());
		v.print();

		vector<int> v1 = v;
		v1.print();
		v1.push_back(100);
		v = v1;
		v.print();


	}
}
