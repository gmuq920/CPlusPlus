#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class date
{
public:
	void Init(int year, int month, int date) 
	{
		this->_year = year;
		this->_month = month;
		this->_date = date;
	}

	void Print() {
		cout << _year << "." << _month << "." << _date << endl;
	}
private:
	int _year;
	int _month;
	int _date;

};

#include <iostream>
#include <string>

using namespace std;

class StudentID {
public:
    // 构造函数
    StudentID(const string& name, int age, int ID, const string& major)
        : _name(name), _age(age), _ID(ID), _major(major) {
    }

    // setter函数
    void setName(const string& name) {
        _name = name;
    }

    void setAge(int age) {
        _age = age;
    }

    void setId(int ID) {
        _ID = ID;
    }

    void setMajor(const string& major) {
        _major = major;
    }

    // getter函数
    string getName() const {
        return _name;
    }

    int getAge() const {
        return _age;
    }

    int getId() const {
        return _ID;
    }

    string getMajor() const {
        return _major;
    }



    void Print() const {
        cout << "Student name: " << _name << "\n"
            << "Student age: " << _age << "\n"
            << "Student ID: " << _ID << "\n"
            << "Student major: " << _major << endl;
    }

    bool operator==(StudentID s2) 
    {
        return _name == s2._name && _age == s2._age && _ID == s2._ID && _major == s2._major;
    }

private:
    string _name;
    int _age;
    int _ID;
    string _major;
};

void isSameStudent(StudentID s1, StudentID s2) 
{
    if (s1 == s2) {
        cout << "Same Student" << endl;
    }
    else
        cout << "Not Same" << endl;
}


int main() {
	/*int a = 10;
	const int& ra = a;
	a++;
	cout << ra << endl;
	return 0;*/
	/*date d1;
	date d2;
	d1.Init(2001, 9, 20);
	d1.Print();*/

	
	
	StudentID s1("Michael", 20, 123453,"Computer science");
    StudentID s2("James", 23, 23123323, "Japanese");
	
	s1.Print();
    s2.Print();
    isSameStudent(s1, s2);


}