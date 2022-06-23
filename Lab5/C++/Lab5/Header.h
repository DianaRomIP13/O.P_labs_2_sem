#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Person {
private:
	string name;
	string date_of_birth;
public:
	Person(string line);
	string getName();
	string count_age();
	virtual double monthly_income(double);
};

class Student : public Person {
private:
	int group_id;
	double average_grade;
	char status;
public:
	Student(string line1 = "none none none 01:01:1970", string line2 = "00 0.0");
	double monthly_income(double) override;
};

class Teacher : public Person {
private:
	string subject;
	int hours;
public:
	int getHours();
	double monthly_income(double) override;
	Teacher(string line1 = "none none none 01:01:1970", string line2 = "none 0");
};

std::vector<string> split(string, char sep = ' ');