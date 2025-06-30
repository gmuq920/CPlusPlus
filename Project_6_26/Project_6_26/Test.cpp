#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Sum {
public:
	Sum()
	{
		_ret += _i;
		_i++;
	}
	static int get_ret() {
		return _ret;
	}
private:
	static int _i;
	static int _ret;
};

int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
	int Sum_Solution(int n) 
	{
		Sum a[10];
		return Sum::get_ret();
	}
};

int main() {
	
	int num = Solution().Sum_Solution(10);
	cout << num << endl;
	return 0;
}