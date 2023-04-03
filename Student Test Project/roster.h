#pragma once
#include "student.h"
class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];
public:
	void parse(std::string row);
	void add(std::string sID,
		std::string sFirstName,
		std::string sLastName,
		std::string sEmailAddress,
		int sAge,
		int sDaysInCourse1,
		int sDaysInCourse2,
		int sDaysInCourse3,
		DegreeProgram degreeProgram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void removeStudentByID(std::string studentID);
	~Roster();
};