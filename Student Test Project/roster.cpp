#include "roster.h"
void Roster::parse(std::string studentData)
{
	

	int rhs = studentData.find(",");
	std::string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	std::string sFirstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	std::string sLastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	std::string sEmailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int sAge = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	
	DegreeProgram degreeProgram = SECURITY;
	if (studentData.at(1) == '1') degreeProgram = SECURITY;
	if (studentData.at(1) == '2') degreeProgram = NETWORK;
	if (studentData.at(1) == '3') degreeProgram = SOFTWARE;
	if (studentData.at(1) == '4') degreeProgram = SECURITY;
	if (studentData.at(1) == '5') degreeProgram = SOFTWARE;
  

	add(sID, sFirstName, sLastName, sEmailAddress, sAge, dInCourse1, dInCourse2, dInCourse3, degreeProgram);

}

void Roster::add(std::string sID, std::string sFirstName, std::string sLastName, std::string sEmailAddress, int sAge, int sDaysInCourse1, int sDaysInCourse2, int sDaysInCourse3, DegreeProgram degreeProgram)
{
	int dic[3] = { sDaysInCourse1, sDaysInCourse2, sDaysInCourse3 };
	
	classRosterArray[++lastIndex] = new Student(sID, sFirstName, sLastName, sEmailAddress, sAge, dic, degreeProgram);
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getID() << '\t';
		cout << classRosterArray[i]->getFirstName() << '\t';
		cout << classRosterArray[i]->getLastName() << '\t';
		cout << classRosterArray[i]->getEmailAddress() << '\t';
		cout << classRosterArray[i]->getAge() << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[0] << ',';
		cout << classRosterArray[i]->getDaysInCourse()[1] << ',';
		cout << classRosterArray[i]->getDaysInCourse()[2] << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;

	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->Print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		std::string sEA = (classRosterArray[i]->getEmailAddress());
		if ((sEA.find('@') == std::string::npos) || (sEA.find('.') == std::string::npos) || (sEA.find(' ') != std::string::npos))
		{
			any = true;
			cout << classRosterArray[i]->getID() << ": " << classRosterArray[i]->getEmailAddress() << std::endl;
		}
		
	}
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
			cout << classRosterArray[i]->getID() << ": ";
		cout << (classRosterArray[i]->getDaysInCourse()[0]
			+ classRosterArray[i]->getDaysInCourse()[1]
			+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << std::endl;
	}
	cout << std::endl;
}

void Roster::removeStudentByID(std::string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true;/*found*/
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];/*swap with last book*/
				classRosterArray[i] = classRosterArray[numStudents - 2];
				classRosterArray[i + 1] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
		if (success)
		{
			cout << studentID << " removed from repository." << std::endl << std::endl;
			this->printAll();
		}
		else cout << studentID << " not found." << std::endl << std::endl;
	
}

Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}



