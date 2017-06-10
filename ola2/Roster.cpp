//Implementation file of Roster.h
//Indludes all function definitions
//of Roster.h


#include "Roster.h"
#include "Student.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//constuctor takes a string as an argument
//and assigns it to m_courseName
Roster::Roster(std::string courseName)
{
	m_courseName = courseName;
	m_studentNum = 0;
}

void Roster::readStudentRecord(std::string file)
{
	//open file
	std::ifstream myIn;
	myIn.open(file);

	//grab first line because it
	//is not student data
	std::string firstline;
	std::getline(myIn, firstline);

	string id;
	int data;

	//prime read and enter loop while reading
	myIn >> id;
	while (myIn)
	{
		//store data from file into 
		//the m_students array
		//store the data according to its subject
		m_students[m_studentNum].setID(id);

		myIn >> data;
		m_students[m_studentNum].changeScore(Student::CLA, data);

		myIn >> data;
		m_students[m_studentNum].changeScore(Student::OLA, data);

		myIn >> data;
		m_students[m_studentNum].changeScore(Student::QUIZ, data);

		myIn >> data;
		m_students[m_studentNum].changeScore(Student::HOMEWORK, data);

		myIn >> data;
		m_students[m_studentNum].changeScore(Student::EXAM, data);

		myIn >> data;
		m_students[m_studentNum].changeScore(Student::BONUS, data);

		//calculate the total for the current student 
		//and set the letter grade for the student
		m_students[m_studentNum].m_totalCalculate();
		m_students[m_studentNum].setLetter();

		//read again and increment to next position in array for next student
		myIn >> id;
		++m_studentNum;
	}

	--m_studentNum;
}

//function prints all student records in current roster
void Roster::printStudentRecord()
{
	//firsline
	cout << "     ID   CLA   OLA   Quiz   Homework   Exam   Bonus   Total   FinalGrade   " << endl;

	//loop through m_student array and print all contents of student object
	for (int i = 0; i < m_studentNum; ++i)
	{
		cout << m_students[i].getID() << '\t';
		cout << m_students[i].getScore(Student::CLA) << '\t';
		cout << m_students[i].getScore(Student::OLA) << '\t';
		cout << m_students[i].getScore(Student::QUIZ) << '\t';
		cout << m_students[i].getScore(Student::HOMEWORK) << '\t';
		cout << m_students[i].getScore(Student::EXAM) << '\t';
		cout << m_students[i].getScore(Student::BONUS) << '\t';
		cout << m_students[i].getTotal() << '\t';
		cout << m_students[i].getLetter() << endl;

	}
}

//this fucntion takes a string as argument
//the string should be a valid student ID
void Roster::printOneRecord(string cnum)
{
	cout << endl << "     ID   CLA   OLA   Quiz   Homework   Exam   Bonus   Total   FinalGrade   " << endl;

	//loop through student array
	for (int i = 0; i < m_studentNum; ++i)
	{
		//until desired student record is found
		//then print all records of the given student ID
		if (m_students[i].getID() == cnum)
		{
			cout << m_students[i].getID() << '\t';
			cout << m_students[i].getScore(Student::CLA) << '\t';
			cout << m_students[i].getScore(Student::OLA) << '\t';
			cout << m_students[i].getScore(Student::QUIZ) << '\t';
			cout << m_students[i].getScore(Student::HOMEWORK) << '\t';
			cout << m_students[i].getScore(Student::EXAM) << '\t';
			cout << m_students[i].getScore(Student::BONUS) << '\t';
			cout << m_students[i].getTotal() << '\t';
			cout << m_students[i].getLetter() << endl << endl;
		}

	}

}
