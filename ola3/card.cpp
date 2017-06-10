//Bryce Ault
//Project: OLA 3
//File: card.cpp

#include "Card.h"
#include <iostream>

//default constructor
Card::Card()
{

}

//constructor for initializing the inividual cards
Card::Card(int facevalue, suite type, int pointValue)
{
	Card::faceValue = facevalue;
	Card::type = type;
	Card::pointValue = pointValue;
}

//operator overload for printing out card values
ostream& operator << (ostream& os, const Card& cd)
{
	//determine if face card
	char faceLetter = ' ';
	if (cd.faceValue == 1)
		faceLetter = 'A';
	else if (cd.faceValue == 11)
		faceLetter = 'J';
	else if (cd.faceValue == 12)
		faceLetter = 'Q';
	else if (cd.faceValue == 13)
		faceLetter = 'K';

	//if not a face card
	if (faceLetter != ' ')
	{
		//determine suite type
		if (cd.getType() == clubs)

			//print card details
			os << faceLetter << ((char)0x05) << '[' << cd.pointValue << ']';
		else if (cd.getType() == hearts)
			os << faceLetter << ((char)0x03) << '[' << cd.pointValue << ']';
		else if (cd.getType() == spades)
			os << faceLetter << ((char)0x06) << '[' << cd.pointValue << ']';
		else
			os << faceLetter << ((char)0x04) << '[' << cd.pointValue << ']';
	}
	else //if face card
	{
		//determine suite type
		if (cd.getType() == clubs)

			//print card details along with face card value
			os << cd.faceValue << ((char)0x05) << '[' << cd.pointValue << ']';
		else if (cd.getType() == hearts)
			os << cd.faceValue << ((char)0x03) << '[' << cd.pointValue << ']';
		else if (cd.getType() == spades)
			os << cd.faceValue << ((char)0x06) << '[' << cd.pointValue << ']';
		else
			os << cd.faceValue << ((char)0x04) << '[' << cd.pointValue << ']';
	}
	return os;
}

//operator overload for comparing card values
bool Card::operator < (const Card& cd) const
{
	//if left is smaller than right
	if (pointValue < cd.pointValue)
		return true;	//return true
	else
		return false;
}

//operator overload for comparing card values
bool Card::operator > (const Card& cd) const
{
	//if left is larger than right
	if (pointValue > cd.pointValue)
		return true;	//return true
	else
		return false;
}

//operator overload for comparing card values
bool Card::operator == (const Card& cd) const
{
	//if the 2 card values are equivalent
	if (pointValue == cd.pointValue)
		return true;	//return true
	else
		return false;
}

//function returns pointValue
int Card::getPointValue() const
{
	return pointValue;
}

//function returns card type
suite Card::getType() const
{
	return type;
}