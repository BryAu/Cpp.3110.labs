//Bryce Ault
//Project: OLA 3
//File: deck.cpp

#include "Deck.h"
#include "Card.h"

Deck::Deck()
{
	//initialize top card
	topCard = 0;
	int cardCount = 0;	//variable to iterate each index of the deck

	//start with first index of theDeck and begin initializing cards
	//beginning with suite type clubs
	theDeck[cardCount] = Card(1, clubs, 15);	//first index starts with Ace
	++cardCount;

	//loop through the rest of suite type clubs
	for (int i = 2; i < 14; ++i)
	{
		//if non-face card
		if (i > 10)
			theDeck[cardCount] = Card(i, clubs, 10);	//assign facevalue to pointvalue
		else
			//if face card (but not Ace)
			theDeck[cardCount] = Card(i, clubs, i);		//assign 10 to pointvalue

		//keep track of all cards initialized
		++cardCount;
	}

	//start with cardCount index of theDeck and begin initializing cards
	//build next suite with suite type hearts
	theDeck[cardCount] = Card(1, hearts, 15);		//ace is first card initialized
	++cardCount;

	//loop through the rest of suite type hears
	for (int i = 2; i < 14; ++i)
	{
		//if non-face card
		if (i > 10)
			theDeck[cardCount] = Card(i, hearts, 10);	//assign facevalue to pointvalue
		else
			//if face card (but not Ace)
			theDeck[cardCount] = Card(i, hearts, i);	//assign 10 to pointvalue

		//keep track of all cards initialized
		++cardCount;
	}

	//Spades next
	theDeck[cardCount] = Card(1, spades, 15);
	++cardCount;
	for (int i = 2; i < 14; ++i)
	{
		if (i > 10)
			theDeck[cardCount] = Card(i, spades, 10);
		else
			theDeck[cardCount] = Card(i, spades, i);

		++cardCount;
	}

	//Lastly, diamonds
	theDeck[cardCount] = Card(1, diamonds, 15);
	++cardCount;
	for (int i = 2; i < 14; ++i)
	{
		if (i > 10)
			theDeck[cardCount] = Card(i, diamonds, 10);
		else
			theDeck[cardCount] = Card(i, diamonds, i);

		++cardCount;
	}
}

//function returns the topCard index in theDeck[]
Card Deck::dealCard()
{
	Card top = theDeck[topCard];
	++topCard;		//increments to next card in theDeck[]
	return top;
}

//function randomly shuffles the deck
void Deck::Shuffle()
{
	//loop through the entire deck 1 card at a time
	for (int i = 0; i < 52; ++i)
	{
		//randomly generate value 0-51
		//which will be used to find a card in the deck
		int randomCard = rand() % 52;

		//swap the current index with the randomly found card
		Card temp = theDeck[i];
		theDeck[i] = theDeck[randomCard];
		theDeck[randomCard] = temp;
	}
}

//returns true if topCard is last card in the deck
bool Deck::isEmpty()
{
	if (topCard == 52)
		return true;
	else
		return false;
}

//operator overload for output
ostream& operator << (ostream& os, const Deck& deck)
{
	//loop through each card in theDeck and output card values
	for (int i = deck.topCard; i < deck.Card_Num; ++i)
		os << deck.theDeck[i] << ' ';
	return os;
}