//Bryce Ault
//Project: OLA 3
//File: player.cpp

#include "Player.h"
#include <string>

using std::string;

//constructor which takes 1 argument
Player::Player(string name)
{
	//assigns that argument name
	Player::name = name;
	Player::score = 0;		//start with a score of 0

	//logic for drawring cards
	for (int i = 0; i < Max_Cards; ++i)
		played[i] = true;	//start with all cards in hand being "played"
}

//function returns 1 card in the players hand
Card Player::playCard()
{
	//generate random int between 0-2
	//or keep generating random
	//numbers until an unplayed card is found
	int randomCard = rand() % 3;
	while (played[randomCard])
		randomCard = rand() % 3;
	//card has now been played
	played[randomCard] = true;
	return hand[randomCard];
}

//function draws topCard of theDeck
void Player::drawCard(Deck& dk)
{
	//loop through players played cards
	for (int i = 0; i < Max_Cards; ++i)
		if (played[i])		//if a card has been played
		{
			hand[i] = dk.dealCard();	//deal new card
			played[i] = false;			//new card has not been played
		}
}

//function takes 1 arugment of type card
void Player::addScore(Card acard)
{
	//adds the point value of the card to score
	score = score + acard.getPointValue();
}

//function returns score
int Player::total() const
{
	return score;
}

//function returns name
string Player::getName() const
{
	return name;
}

//function returns true if all values in played[] are true
bool Player::emptyHand() const
{
	//loop through hand array
	for (int i = 0; i < 3; ++i)
		if (!played[i])		//if false is found in array
			return false;	//return false
	
	return true;			//else return true
}

//operator overload for ostream
ostream& operator << (std::ostream& os, const Player& player)
{
	//loop through players hand
	for (int i = 0; i < Player::Max_Cards; ++i)

		//if the position in played[] is false, then output
		if (!player.played[i])			
			os << player.hand[i] << ' ';
		else
			os << " ____ ";
	return os;
}