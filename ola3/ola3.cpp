//Bryce Ault
//Project: OLA 3
//File: ola3.cpp

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	//declare 2 variables of type Player
	//constructor takes in name of player as argument
	Player player1 = Player("William");
	Player player2 = Player("Computer");

	//declare a deck variable of type Deck
	Deck deck = Deck();

	//output the deck
	cout << "The original deck has the following cards: " << endl;
	cout << deck << endl << endl;

	//suffle the deck, then output the deck
	cout << "After shuffle, the deck has the following cards: " << endl;
	deck.Shuffle();
	cout << deck << endl << endl;

	//variable decalaration
	Card player1Card;		//these variable of type Card will help determine
	Card player2Card;		//the winner of the hand

	//count number of hands played
	int counter = 1;	
	do 	
	{
		//each Player draws cards from theDeck[] if 
		//cards in hand have been played
		if (!deck.isEmpty())
		{
			player1.drawCard(deck);
			player2.drawCard(deck);
		}

		//print player name, current hand, and current score
		cout << "************** Hand " << counter << " **************" << endl;
		cout << player1.getName() << "'s hand: " << player1 << " with a score " << player1.total() << endl;
		cout << player2.getName() << "'s hand: " << player2 << " with a score " << player2.total() << endl << endl;

		//store played cards in variables
		player1Card = player1.playCard();
		player2Card = player2.playCard();

		//output played cards information
		cout << player1.getName() << " played card: " << player1Card << " --- " << player2.getName() << " played card: " << player2Card << endl << endl;

		//if played cards are equivalent
		if (player1Card == player2Card)
		{
			//output a tie
			cout << "This hand ended in a tie." << endl;
		}

		//if player1 card is greater than player2 card
		else if (player1Card > player2Card)
		{
			//then player 1 wins and score gets added to player1 score
			cout << player1.getName() << " takes this hand." << endl;
			player1.addScore(player1Card);
		}
		else
		{
			//else, then player 2 wins and score get addes to player2 score
			cout << player2.getName() << " takes this hand." << endl;
			player2.addScore(player2Card);
		}

		//output player hands after cards have been played
		cout << player1.getName() << "'s hand: " << player1 << " with a score " << player1.total() << endl;
		cout << player2.getName() << "'s hand: " << player2 << " with a score " << player2.total() << endl << endl;
		
		//incerement to next hand
		++counter;
	} while (!player1.emptyHand());

	//compare player totals and the player with highest score wins, or else result is a tie
	if (player1.total() > player2.total())
		cout << player1.getName() << " wins with a score of " << player1.total() << endl;
	else if (player1.total() > player2.total())
		cout << player2.getName() << " wins with a score of " << player2.total() << endl;
	else
		cout << "The players have ended in a tie." << endl;

	return 0;
}