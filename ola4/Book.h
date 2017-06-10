//Bryce Ault
//Project: ola4
//File: Book.h


#pragma once
#include "StoreItem.h"
#include <string>

class Book : public StoreItem
{
public:
	//default constructor setting every thing to empty or 0
	Book(std::string title = "", std::string author = "",
		std::string barcode = "", double price = 0, int copy = 0, int demand = 0, std::string date = "");

	std::string getAuthor() const override;
	
	std::string getDate() const;


	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info must be of the line format specificed in
	//inventory.txt
	Book* createFromString(const std::string info) override;

	//Print current item to the screen
	void printItem() override;

private:
	std::string m_author;     // book author
	std::string m_date;			//book publish date
};
