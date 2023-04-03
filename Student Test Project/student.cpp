#include "student.h"
Student::Student()
{

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;

}

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstname) { this->firstName = firstname; }
void Student::setLastName(string lastname) { this->lastName = lastname; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress;}
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram; }

void Student::printHeader()
{
	cout << "Student ID|First Name|Last Name|Email|Age|Days in Course|Degree Program\n";

}

void Student::Print()
{
	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}
