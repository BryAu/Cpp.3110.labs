//Bryce Ault
//Project: ola4
//File: movie.cpp


#include "Movie.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

//constructor
//initializes all data members
Movie::Movie(string title, string director,
	string barcode, double price, int copy, int demand)
	//initializer list
	//call base class contrusctor first
	//then initialize new data members
	:StoreItem(barcode, price, copy, demand, title), m_director(director)
{}

//function returns the title of current object
//string Movie::getTitle() const
//{	return m_title;		}

//function returns the director's name of current object
string Movie::getDirector() const
{	return m_director;		}

//function creates an object from a string argument
Movie* Movie::createFromString(const string info)
{
	//stringstream
	stringstream ss(info);
	string barcode, title, director, price, copies, demand;

	//first getline returns garbage value
	std::getline(ss, barcode, DELIMITER);
	std::getline(ss, barcode, DELIMITER);	//this getline returns item type, 
											//Book or Movie (in this case only movie)

	//store the rest of data
	std::getline(ss, barcode, DELIMITER);
	std::getline(ss, title, DELIMITER);
	std::getline(ss, director, DELIMITER);
	std::getline(ss, price, DELIMITER);
	std::getline(ss, copies, DELIMITER);
	std::getline(ss, demand, DELIMITER);

	//convert data appropriately
	char* EndPtr;
	double d_price = strtod(price.c_str(), &EndPtr);	//str price to double
	int i_copies = atoi(copies.c_str());				//str copies to int
	int i_demand = atoi(demand.c_str());				//str demand to int

	//call constructor with data
	//and assign a pointer to point to the new object
	Movie* newMovie = new Movie(title, director, barcode, d_price, i_copies, i_demand);
	return newMovie;	//return pointer
}

//function prints the contents of current object
void Movie::printItem()
{
	cout << endl << "*********************" << "Movie with barcode " << getBarcode() << " *******************" << endl;
	cout << "Title: \t\t" << getTitle() << endl;
	cout << "Director: \t" << getDirector() << endl;
	cout << "Price: \t\t" << getPrice() << endl;
	cout << "# of copy: \t" << getCopy() << endl;
	cout << "# of demand: \t" << getDemand() << endl << endl;
}