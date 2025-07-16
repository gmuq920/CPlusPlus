#include<iostream>
#include<vector>
using namespace std;

//template<class T>
//class Stack :public vector<T> 
//{
//
//public:
//	void push(const T& x) 
//	{
//		vector<T>::push_back(x);
//	}
//
//	void pop()
//	{
//		vector<T>::pop_back();
//	}
//
//	const T& top() 
//	{
//		return vector<T>::back();
//	}
//
//	size_t size() 
//	{
//		return vector<T>::size();
//	}
//    void print() 
//	{
//		int num = size();
//		for (int i = 0; i < num; i++)
//		{
//			cout << top()<<" ";
//			pop();
//		}
//	}
//
//	bool empty() {
//		return vector<T>::empty();
//	}
//};
//
//int main() {
//	Stack<int> s;
//	s.push_back(3);
//	s.push_back(2);
//	s.push_back(1);
//	s.print();
//
//
//	return 0;
//}

class Person 
{
public:
	void set_age(int x) 
	{
		_age = x;
	}

	int get_age() {
		return _age;
	}

	void eat() 
	{
		cout << "Eat" << endl;
	}
private:
	int _age;
};

class Student :public Person 
{
public:
	void study() {
		cout << "Study" << endl;
	}

	void eat() 
	{
		cout << "Student Eat" << endl;
	}

	void set_major(char x) 
	{
		_major = x;
	}

	char get_major() {
		return _major;
	}
private:
	char _major;

};

class Teacher :public Person 
{
public:
	void teach() {
		cout << "Teach"<<endl;
	}
};

int main() 
{
	Student s1;
	s1.set_age(18);
	Student s2;
	s2.set_age(30);
	Person p1 = s1;
	cout <<"p1.age = "<< p1.get_age() << endl;
	Teacher t1;
	Person& rp = s2;
	rp.set_age(12);
	
	cout << "s2.age = " << s2.get_age() << endl;
	s2.study();
	t1.teach();
	s1.eat();
	s1.Person::eat();
	p1.eat();
	
	
	return 0;
}