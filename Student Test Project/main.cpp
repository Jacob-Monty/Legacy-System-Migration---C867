#include "roster.h"
//using std:: endl;
int main()
{
	const std::string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jacob,Montoya,jmon329@wgu.edu,28,20,30,45,SOFTWARE"
	};

	cout << "C867 - Scripting & Programming: Applications" << std::endl;
	cout << "Language: C++" << std::endl;
	cout << "Student ID: 001433510" << std:: endl;
	cout << "Name: Jacob Montoya" << std::endl;
	cout << std::endl;


	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; ++i) classRoster.parse(studentData[i]);
	cout << "Displaying all Students : " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "Displaying students with Invalid Emails" << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average days in courses: " << std::endl;
	classRoster.printAverageDaysInCourse(classRoster.classRosterArray[0]->getID());
	cout << std::endl;

	for (int i = 2; i < 3; i++)
	{
		cout << "Displaying by Degree Program : " << degreeProgramStrings[2] << std::endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);
	};

	cout << "Removing Student with Student ID A3:" << std::endl;
	classRoster.removeStudentByID("A3");
	cout << std::endl;


	cout << "Removing Student with Student ID A3:" << std::endl;
	classRoster.removeStudentByID("A3");
	cout << std::endl;

	system("pause");
	return 0;
}