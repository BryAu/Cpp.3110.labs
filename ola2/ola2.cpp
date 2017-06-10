//Bryce Ault
//OLA 2
//CSCI 3110
//Dr. Dong


#include <fstream>
#include <iostream>
#include <string>
#include "Roster.h"
#include "Student.h"

using std::ifstream;
using std::string;
using std::cout;
using std::cin;

int main()
{
	//store file path in variable for later
	string filePath = "point.dat";
	//creat a roster object and assign coursename to CSCI3110
	Roster rosterOne("CSCI3110");

	//read data file into the roster object
	rosterOne.readStudentRecord(filePath);

	//have user search for a valid student id
	//and print desired student records
	string cnum;
	cout << "Enter a valid student c-number: ";
	cin >> cnum;
	rosterOne.printOneRecord(cnum);

	//print all the records of the roster object
	rosterOne.printStudentRecord();


	return 0;

}