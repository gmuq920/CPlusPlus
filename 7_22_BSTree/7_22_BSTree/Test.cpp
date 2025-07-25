#include"BinarySearch.h"

int main() {
	BSTree<int> T;
	int i[10] = { 1,3,2,4,7,5,89,90,6,11111 };
	for (auto e : i)
	{
		T.Insert(e);
	}

	T.InOrder();
	

	return 0;
}