#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class A 
//{
//	public:
//		A(int a = 0)
//			:_a(a)
//		{
//			cout << "A(int a)" << endl;
//		}
//
//		A(const A& aa)
//			:_a(aa._a)
//		{
//			cout << "A(const A& aa)" << endl;
//		}
//		~A() 
//		{
//			cout << "~A" << endl;
//		}
//		void Print() {
//			cout << "A::Print->" << _a << endl;
//		}
//
//		A& operator++() 
//		{
//			++_a;
//			return *this;
//		}
//		
//private:
//	int _a = 1;
//};
//
//A f1() 
//{
//	A aa(1);
//	++aa;
//	return aa;
//}
//
//
//template <class T1,class T2>
//T1 Add(const T1& x,const T2& y)
//{
//	return x + y;
//}
//
//template <class T>
//T Add(const T& x, const T& y) {
//	return x + y;
//}
//
//int main() 
//{
//	/*A aa1 = 3;
//	const A& aa2 = 1;*/
//	/*A aa = 1; 
//	f1(aa);
//	cout << endl;
//
//	f1(1);
//	cout << endl;
//
//	f1(A(1));
//	cout << endl;*/
//	
//	//f1().Print();
//	int x = 1;
//	double y = 3.5;
//
//	cout<< Add(x , y)<<endl;
//
//	double z = Add<double>(x, y);
//	cout << z << endl;
//
//	return 0;
//}

template<typename T>
class Stack 
{
public:
	Stack(int n = 4)
		:_array(new T[n]),
		_size(0),
		_capacity(n){}

	~Stack()
	{
		delete[] _array;
		_array = nullptr;
		_capacity = 0;
		_size = 0;
	}

	void Push(const T& x) 
	{
		if (_size == _capacity) 
		{
			T* tmp = new T[_capacity * 2];
			memcpy(tmp, _array, sizeof(T)*_size);
			delete[] _array;
			_array = tmp;
			_capacity *= 2;
		}
		_array[_size++] = x;
	}

	void Print() 
	{
		for (int i = 0;i < _size;i++) {
			cout << _array[i] << endl;
		}
	}
private:
	T* _array;
	
	size_t _size;
	size_t _capacity;
};

int main() {
	Stack<double> s1;
	s1.Push(3.3);
	s1.Push(2.98);
	s1.Push(5.5);
	s1.Push(23);
	s1.Print();

	Stack<char>s2;
	s2.Push('a');
	s2.Push('b');
	
	s2.Print();

	return 0;
}