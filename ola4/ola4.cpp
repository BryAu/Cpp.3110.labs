//Bryce Ault
//Project: ola4
//File: ola4.cpp

#include "StoreItem.h"
#include "Book.h"
#include "Movie.h"
#include <string>
#include <iostream>
#include <fstream>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::list;
using std::endl;

int main()
{
	//variable declaration
	//default objects for class Movie and Book
	Book defaultBook;
	Movie defaultMovie;
	
	//to store a line from data file
	string itemInfo;

	//list of base class
	//and iterator for that list
	//and pointer to point at items in that list
	list<StoreItem*> storeList;
	list<StoreItem*>::iterator iter = storeList.begin();
	StoreItem* itemptr;

	//open text file
	std::ifstream inventoryFile;
	inventoryFile.open("inventory.txt");

	//read all
	while (std::getline(inventoryFile, itemInfo))
	{
		//if movie
		//then build from Movie class
		if (itemInfo[1] == 'M')
			itemptr = defaultMovie.createFromString(itemInfo);
		
		//else build from Book class
		else
			itemptr = defaultBook.createFromString(itemInfo);

		//insert item into the list
		storeList.insert(iter, itemptr);
	}

	//variable for store command character from standard input
	char command;
	
	do		//at least once
	{
		//print the menu options
		cout << "\t\t\t MiniMovie Store \n" << "****************************************************** \n";
		cout << "* Command\tDescription \t\t\t\t*" << endl;
		cout << "* M\t\tInquire a movie by title\t\t*" << endl;
		cout << "* B\t\tInquire a book by author\t\t*" << endl;
		cout << "* L\t\tList inventory\t\t\t\t*" << endl;
		cout << "* R\t\tReturn one movie\t\t\t*" << endl;
		cout << "* C\t\tCheck out\t\t\t\t*" << endl;
		cout << "* Q\t\tQuit to main menu\t\t\t*" << endl;
		cout << "******************************************************" << endl;
		cout << "Please enter your command (M, B, L, R, C, Q): ";
		cin >> command;	//read command char

		//print list
		//if command char is 'L' or 'l'
		if (command == 'L' || command == 'l')
		{
			//iterate through the list and print each item
			for (iter = storeList.begin(); iter != storeList.end(); ++iter)
			{
				itemptr = *iter;
				itemptr->printItem();
			}
		}

		//checkout item
		//if command char is 'C' or 'c'
		else if (command == 'C' || command == 'c')
		{
			//store barcode input
			string barcode;
			bool found = false;	//boolean for if object is found or not

			//enter barcode
			cout << "\nPlease enter the item barcode: ";
			cin >> barcode;

			//iterate through list
			for (iter = storeList.begin(); iter != storeList.end(); ++iter)
			{
				//if barcode is found in the list of StoreItems
				itemptr = *iter;
				if (itemptr->getBarcode() == barcode)
				{
					//increment demand if # of copies is 0
					found = true;
					if (itemptr->getCopy() == 0)
						itemptr->increaseDemand();

					//else decrease # of copies
					else
						itemptr->decreaseCopy();
					cout << "\nThe item " << barcode << " has been check out successfully!\n";
				}
			}
			//if item was not found in the list
			if (!found)
				cout << "Cannot find item with barcode \"" << barcode << '\"' << endl;
		}

		//return item
		//if command char is 'R' or 'r'
		else if (command == 'R' || command == 'r')
		{
			//store barcode input
			string barcode;
			bool found = false;	//boolean for if object is found or not

			//enter barcode
			cout << "\nPlease enter the item barcode: ";
			cin >> barcode;

			//iterate through the list of StoreItems
			for (iter = storeList.begin(); iter != storeList.end(); ++iter)
			{
				//if barcode is found
				itemptr = *iter;
				if (itemptr->getBarcode() == barcode)
				{
					//increment number of copies
					found = true;
					itemptr->increaseCopy();
					cout << "\nThe item " << barcode << " has been returned successfully!\n";
				}
			}
			//if barcode is not found
			if (!found)
				cout << "Cannot find item with barcode \"" << barcode << '\"' << endl;
		}

		//print item by title
		//if command char is 'M' or 'm'
		else if (command == 'M' || command == 'm')
		{
			//user enter title to search
			cout << "\nPlease enter the movie title: \n";
			string movieTitle;
			bool found = false;	//boolean for if item is found or not

			//pause for input, then read the input
			cin.get();
			std::getline(cin, movieTitle);

			//iterate through StoreItem list
			for (iter = storeList.begin(); iter != storeList.end(); ++iter)
			{
				//if Title is found, then print item contents
				itemptr = *iter;
				if (itemptr->getTitle() == movieTitle)
				{
					itemptr->printItem();
					found = true;
				}
			}
			if (!found)
				cout << "Cannot find item with barcode \"" << movieTitle << '\"' << endl;
		}

		//search book by author
		//if command char is 'B' or 'b'
		else if (command == 'B' || command == 'b')
		{
			//user enter name to search
			string authorName;
			cout << "\nPlease enter the author name: \n";
			bool found = false;	//boolean for if item is found or not

			//pause for input, then read the input
			cin.get();
			std::getline(cin, authorName);

			//iterate through StoreItem list
			for (iter = storeList.begin(); iter != storeList.end(); ++iter)
			{
				//if found, then print item contents
				itemptr = *iter;

				//if Author string of current
				//object contains substring "authorName"
				size_t foundName = itemptr->getAuthor().find(authorName);
				if (foundName != string::npos)
				{
					itemptr->printItem();
					found = true;
				}
			}

			if(!found)
				cout << "Cannot find item with author \"" << authorName << '\"' << endl;
		}

		//if command is 'Q' or 'q' then break out of loop
		else if (command == 'Q' || command == 'q')
			break;

		//pause system for user to read
		//then clear console window on keypress
		system("pause");
		system("cls");
	} while (command != 'Q' || command != 'q');
	return 0;
}