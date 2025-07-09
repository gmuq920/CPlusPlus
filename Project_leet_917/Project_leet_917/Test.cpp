#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<string>

//
//
//class Solution {
//public:
//    string reverseOnlyLetters(string s)
//    {
//        string sNew = s;
//        int size = s.size();
//        int cur = 0;
//        string::reverse_iterator it = s.rbegin();
//        while (it != s.rend())
//        {
//            if (((*it >= 65) && (*it <= 90)) || ((*it >= 97) && (*it <= 122)))
//            {
//                while (!(((sNew[cur] >= 65) && (sNew[cur] <= 90)) || ((sNew[cur] >= 97) && (sNew[cur] <= 122))))
//                {
//                     cur++;
//                }
//                sNew[cur] = *it;
//                cur++;
//            }
//            it++;
//        }
//        return sNew;
//
//    }
//};
//
//int main() 
//{
//    cout << Solution().reverseOnlyLetters("a-bC-dEf-ghIj");
//}
//

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int size1 = num1.size();
        int size2 = num2.size();
        int count1 = 0;
        int count2 = 0;
        for (int i = 0;i < size1;i++)
        {
            count1 += (pow(10, i) * (num1[size1 - i - 1]-48));
        }
        for (int i = 0;i < size2;i++)
        {
            count2 += (pow(10, i) * (num2[size2 - i - 1]-48));
        }
        int ret = count1 + count2;
        string s = to_string(ret);
        return s;
    }
};

int main() {
    cout << Solution().addStrings("11", "123");
}