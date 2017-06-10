//Bryce Ault
//Project: ola4
//File: storeitem.cpp

#include "StoreItem.h"
#include <string>

using std::string;

//constructor
//initializes all data members
StoreItem::StoreItem(string barcode, double price, int copy, int demand, string title)
	:m_barcode(barcode), m_price(price), m_copy(copy), m_demand(demand), m_title(title)
{}

//function returns the
//barcode of current object
string StoreItem::getBarcode(void) const
{	return m_barcode;	}

//function returns the
//price of current object
double StoreItem::getPrice(void) const
{	return m_price;		}

//function returns the
//number of copies of current object
int StoreItem::getCopy(void) const
{	return m_copy;		}

//function returns the
//demand of current object
int StoreItem::getDemand(void) const
{	return m_demand;	}

string StoreItem::getTitle() const
{	return m_title;		}

//function increases # of
//copies of current object by 1
void StoreItem::increaseCopy(void)
{	
	if(getCopy() >= 0)
		++m_copy;	
}

//function decreases # of
//copies of current object by 1
void StoreItem::decreaseCopy(void)
{	
	if(getCopy() > 0)
		--m_copy;	
}

//function increases the
//demand (# of copies to be ordered)
//if # of copies is 0
void StoreItem::increaseDemand(void)
{
	if (getCopy() == 0)
		++m_demand;
}

//function decreases the
//demand by 1 if demand
//is greater than 0
void StoreItem::decreaseDemand(void)
{
	if (getDemand() > 0)
		--m_demand;
}

//operator == overload
bool StoreItem::operator == (const StoreItem& rhs) const
{
	//if current object's barcode
	//is euqivalent to compared object
	return (m_barcode == rhs.m_barcode);
}

//operator < overload
bool StoreItem::operator < (const StoreItem& rhs) const
{
	//if current object's barcode
	//is less than compared object
	return (m_barcode < rhs.m_barcode);
}

//return m_author
//used in Book class
string StoreItem::getAuthor() const
{	return "";	}