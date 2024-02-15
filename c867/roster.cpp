#include "roster.h"

Roster::Roster()
{
}



void Roster::parse(string studentData)
{
	Degree degreeType = SECURITY;
	if (studentData.back() == 'K') degreeType = NETWORK;
	else if (studentData.back() == 'E') degreeType = SOFTWARE; 

	int rhs = studentData.find(","); 
	string StudentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FirstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string Email = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days3 = stoi(studentData.substr(lhs, rhs - lhs));


	add(StudentID, FirstName, LastName, Email, Age, Days1, Days2, Days3, degreeType);

}


void Roster::add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, Degree degreetype)
{
	int Days[3] = { Days1, Days2, Days3 };

	classRosterArray[++LastIndex] = new Student(StudentID, FirstName, LastName, Email, Age, Days, degreetype);
}

void Roster::printAverageDaysInCourse(string StudentID)
{
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			cout << " Student ID: ";
			cout << StudentID;
			cout << ",";
			cout << " averages ";
			cout << (classRosterArray[i]->getDays()[0] +
				classRosterArray[i]->getDays()[1] +
				classRosterArray[i]->getDays()[2]) / 3;
			cout << " days in a course.";


		}

	}cout << endl;
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmail(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDays()[0]; cout << '\t';
		cout << classRosterArray[i]->getDays()[1]; cout << '\t';
		cout << classRosterArray[i]->getDays()[2]; cout << '\t';
		cout << degreeTypeStrings[classRosterArray[i]->getDegree()] << std::endl;
	}
}




void Roster::printInvalidEmails() {
	for (int i = 0; i < LastIndex; ++i) {
		bool hasSpaces = false;
		bool hasPeriod = false;
		bool hasAtSymbol = false;

		string Email = this->classRosterArray[i]->getEmail();

		if (Email.find(' ') != string::npos) {
			hasSpaces = true;
		}

		for (int j = 0; j < Email.size(); ++j) {
			char characterN = Email[j];
			if (characterN == '.') {
				hasPeriod = true;
			}
			if (characterN == '@') {
				hasAtSymbol = true;
			}
		}

		if (hasSpaces || hasPeriod == false || hasAtSymbol == false) {
			cout << Email << " - ";

			if (hasSpaces) {
				cout << "contains spaces, ";
			}

			if (hasPeriod == false) {
				cout << "missing period, ";
			}

			if (hasAtSymbol == false) {
				cout << "missing @ symbol, ";
			}

			cout << "which are not allowed." << endl;
		}
	}
}


void Roster::printByDegree(Degree degreeType)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::LastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegree() == degreeType) classRosterArray[i]->print();
	}
	cout << std::endl;


}


void Roster::remove(string StudentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::LastIndex--;



		}

	}
	if (success)
	{
		cout << StudentID << " removed from roster." << endl << std::endl;
		this->printAll();
	}

	else cout << StudentID << " studentID not found" << std::endl << std::endl;

}

Roster::~Roster()
{
	cout << "Destructor Called" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying Student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;

	}

};














	





