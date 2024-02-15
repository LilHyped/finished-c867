#include "student.h"

Student::Student() //constructor

{
	this->StudentID = "";
	this->FirstName = "";
	this->LastName = "";
	this->Email = "";
	this->Age = 0;
	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = 0;
	this->degreeType = Degree::SECURITY; // default value
}

Student::Student(string StudentId, string FirstName, string LastName, string EmailAddress, int Age, int Days[], Degree degreeType) //constructor

{
	this->StudentID = StudentId;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->Email = Email;
	this->Age = Age;
	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = Days[i];
	this->degreeType = degreeType;
}

Student::~Student() {} //destructor

// Accessors - Getters

string Student::getStudentID() { return this->StudentID; }
string Student::getFirstName() { return this->FirstName; }
string Student::getLastName() { return this->LastName; }
string Student::getEmail() { return this->Email; }
int Student::getAge() { return this->Age; };
int* Student::getDays() { return this->Days; }
Degree Student::getDegree() { return this->degreeType; }

// Mutators - Setters

void Student::setStudentID(string StudentID) { this->StudentID = StudentID; }
void Student::setFirstName(string FirstName) { this->FirstName = FirstName; }
void Student::setLastName(string LastName) { this->LastName = LastName; }
void Student::setEmail(string Email) { this->Email = Email; }
void Student::setAge(int Age) { this->Age = Age; }
void Student::setDays(int Days[])


{

	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = Days[i];

}
void Student::setDegree(Degree degreetype) { this->degreeType = degreetype; }

void Student::printHeader()//to print student data
{
	cout << "Output format: StudentID|FirstName|LastName|Email|Age|DaysInCourse|DegreeType\n";
}

void Student::print()
{
	cout << this->getStudentID() << '\t'; 
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << degreeTypeStrings[this->getDegree()] << '\n';

};























