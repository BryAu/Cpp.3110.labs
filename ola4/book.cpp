//Bryce Ault
//Project: ola4
//File: book.cpp


#include "Book.h"
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
Book::Book(string title, string author,
	string barcode, double price, int copy, int demand, string date)
	//initializer list
	//call base class contrusctor first
	//then initialize new data members
	:StoreItem(barcode, price, copy, demand, title), m_author(author), m_date(date)
{}

//function returns the title of current object
//string Book::getTitle() const
//{	return m_title;		}

//function returns the director's name of current object
string Book::getAuthor() const
{	return m_author;	}

//function returns the publishing date of current object
string Book::getDate() const
{	return m_date;		}

//function creates an object from a string argument
Book* Book::createFromString(const string info)
{
	//stringstream
	stringstream ss(info);
	string barcode, title, author, price, copies, demand, date;

	//first getline returns garbage value
	std::getline(ss, barcode, DELIMITER);	
	std::getline(ss, barcode, DELIMITER);	//this getline returns item type, 
											//Book or Movie (in this case only book)

	//store the rest of data
	std::getline(ss, barcode, DELIMITER);
	std::getline(ss, title, DELIMITER);
	std::getline(ss, author, DELIMITER);
	std::getline(ss, date, DELIMITER);
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
	Book* newBook = new Book(title, author, barcode, d_price, i_copies, i_demand, date);
	return newBook;		//return pointer
}

//function prints the contents of current object
void Book::printItem()
{
	cout << endl << "*********************" << "Book with barcode " << getBarcode() << " *******************" << endl;
	cout << "Title: \t\t" << getTitle() << endl;
	cout << "Author: \t" << getAuthor() << endl;
	cout << "Publish Date: \t" << getDate() << endl;
	cout << "Price: \t\t" << getPrice() << endl;
	cout << "# of copy: \t" << getCopy() << endl;
	cout << "# of demand: \t" << getDemand() << endl << endl;
}