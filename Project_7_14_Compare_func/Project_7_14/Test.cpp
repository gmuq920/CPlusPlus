#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
class Greater{
public:
	bool operator()(const T& x, const T& y) 
	{
		return x > y;
	}
};

template<class T>
class Less {
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class Compare>
void Bubble_Sort(int* a,int nums,Compare con)
{
	int size = nums;
	while (size > 0)
	{
		for (int i = 0; i < size-1; i++) {
			if (con(a[i], a[i + 1])) {
				swap(a[i], a[i + 1]);
			}
		}
		size--;
	}
}

int main() {
	int a[5] = { 1,7,2,5,9 };
	Greater<int>Greater;
	Less<int>Less;

	Bubble_Sort(a, 5, Less);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}

	cout << endl;
	Bubble_Sort(a, 5, Greater);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	return 0;
}