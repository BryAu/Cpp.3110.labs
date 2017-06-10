//Implementation file for Student.h
//Indludes all function definitions for
//the Student.h file

#include "Student.h"
#include <string>

using std::string;

//constuctor
Student::Student()
{

}

//this function returns m_id
//which is the ID of the student
string Student::getID() const
{
	return m_id;
}

//this function takes a string as argument
//and assigns it to m_id
void Student::setID(string id)
{
	m_id = id;
}

//function takes 2 arguments
//first argument specifies the enum to access
//second argument assigns a value to the enum
void Student::changeScore(const ScoreType type, const int score)
{
	m_score[type] = score;
}

//function returns the value stored in the enum
//that is passed by value
int  Student::getScore(const ScoreType type) const
{
	return m_score[type];
}

//this function calculates the total score for a single student
void Student::m_totalCalculate()
{
	int total = 0;

	//loop through all scores stores in m_score
	//and add them up
	for (int i = 0; i < 6; ++i)
		total += getScore((ScoreType)i);

	//assign the total to m_total
	m_total = total;
}

//this function returns m_total
int Student::getTotal() const
{
	return m_total;
}

//this function determines the final letter
//grade for the student based on 
//the m_total
void Student::setLetter()
{
	if (m_total > 90)
		m_letterGrade = 'A';
	else if (m_total > 80)
		m_letterGrade = 'B';
	else if (m_total > 70)
		m_letterGrade = 'C';
	else if (m_total > 60)
		m_letterGrade = 'D';
	else
		m_letterGrade = 'F';
}

//function returns the letter grade for a single student
char Student::getLetter() const
{
	return m_letterGrade;
}