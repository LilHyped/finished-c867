#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student
{
public:

	const static int DaysInCourse = 3;


private:

	string StudentID;
	string FirstName;
	string LastName;
	string Email;
	int Age;
	int Days[DaysInCourse];
	Degree degreeType;

public:

	Student(); //constructor
	Student(string StudentID, string FirstName, string LastName, string Email, int Age, int Days[], Degree degreeType);
	~Student(); //destructor

//mutator-setters

	void setStudentID(string StudentID);
	void setFirstName(string FirstName);
	void setLastName(string LastName);
	void setEmail(string Email);
	void setAge(int Age);
	void setDays(int DaysInCourse[]);
	void setDegree(Degree degreeType);

	//accessors-getters

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	Degree getDegree();

	static void printHeader(); //prints student data

	void print();

};