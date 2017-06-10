//Bryce Ault
//c1002303
//This program reads data from an input file and stores that data in an array, then prints it

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;

//struct for storing student data
struct Student {
	//c#
	string ID;

	//grades
	double cla, ola, quiz, hw, exam, bonus, total;
	char finalGrade;
};

//function prototypes
void readFile(Student Roster[17], string &firstLine);
void printOne(Student Roster[17]);
void printRoster(Student Roster[17], string firstLine);

int main() {
	//array of student data
	Student Roster[17];

	//read the data file and grab first line
	string firstLine;
	readFile(Roster, firstLine);

	//for printing 1 student
	printOne(Roster);

	//for printing whole roster
	printRoster(Roster, firstLine);

	return 0;
}

//function to print entire roster
void printRoster(Student Roster[17], string firstLine) {
	//print first line 
	cout << firstLine << endl;
	
	//loop through every student in roster
	int count = 0;
	while (count < 17) {

		//print data
		cout << Roster[count].ID << "\t" << Roster[count].cla << "\t" << Roster[count].ola << "\t" << Roster[count].quiz << "\t" <<
			Roster[count].hw << "\t" << Roster[count].exam << "\t" << Roster[count].bonus << "\t" << Roster[count].total << "\t" <<
			Roster[count].finalGrade << endl;

		count++;
	}
	return;
}

//function to print 1 student from standard input
void printOne(Student Roster[17]) {
	
	//input the c-number to search
	string studentID;
	cout << "Please enter student's c-number: " << endl;
	cin >> studentID;

	//traverse the roster until c-number is found
	int count = 0;
	while (count < 17 && studentID != Roster[count].ID) {
		count++;
	}

	//if not found in roster, invalid input
	if (studentID != Roster[count - 1].ID)
		cout << "Invalid c-number." << endl;

	//if found in the roster
	else
		//print student data
	cout << Roster[count].ID << "\t" << Roster[count].cla << "\t" << Roster[count].ola << "\t" << Roster[count].quiz << "\t" <<
		Roster[count].hw << "\t" << Roster[count].exam << "\t" << Roster[count].bonus << "\t" << Roster[count].total << "\t" <<
		Roster[count].finalGrade << endl;

	return;
}

//function to read data file and store data in array
void readFile(Student Roster[17], string &firstLine) {
	//open file
	ifstream myIn;
	myIn.open("point.dat");

	//grab first line because it
	//is not student data
	getline(myIn, firstLine); 
	

	int count = 0;
	myIn >> Roster[count].ID; //prime read

	//while reading file
	while (myIn) {
		//calculate sum of scores
		int sum = 0;

		//store data and add to scores
		myIn >> Roster[count].cla;
		sum += Roster[count].cla;

		myIn >> Roster[count].ola;
		sum += Roster[count].ola;

		myIn >> Roster[count].quiz;
		sum += Roster[count].quiz;

		myIn >> Roster[count].hw;
		sum += Roster[count].hw;

		myIn >> Roster[count].exam;
		sum += Roster[count].exam;

		myIn >> Roster[count].bonus;
		sum += Roster[count].bonus;

		//total points earned = sum
		Roster[count].total = sum;

		//determine letter grade
		if (sum >= 90)
			Roster[count].finalGrade = 'A';
		else if (sum >= 80)
			Roster[count].finalGrade = 'B';
		else if (sum >= 70)
			Roster[count].finalGrade = 'C';
		else if (sum >= 60)
			Roster[count].finalGrade = 'D';
		else
			Roster[count].finalGrade = 'F';

		//increment to next student
		count++;
		myIn >> Roster[count].ID; //read next data
	}
	return;
}