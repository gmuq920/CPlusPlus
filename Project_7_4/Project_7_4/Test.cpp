#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

void TestStr() {
	string s1;
	string s2("hello world!!");
	for (int i = 0;i < s2.size();i++) {
		cout << s2[i];
	}
	cout << endl;
	string::iterator it = s2.begin();
	while (it != s2.end()) 
	{
		cout << *it;
		it++;
	}
	cout << endl;
	cout << s2.size() << endl;
	cout << s2.length() << endl;
	cout << s2.capacity() << endl;
	
}


//There are four iterators we always use, 
//iterator, reverse_iterator,
//const_iterator, const_reverse_iterator.
int main() 
{
	TestStr();
	return 0;
}