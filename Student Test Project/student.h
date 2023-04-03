#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

class Student 
{
public:
	const static int daysInCourseArraySize = 3;
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourse[daysInCourseArraySize];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	~Student();//destructor

	/*getters aka accessors*/
	std::string getID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	/*setter aka mutators*/
	void setID(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader(); /*displays a header for the data to follow*/

	void Print(); /*displays this students data*/

};