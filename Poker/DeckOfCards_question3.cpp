#include "DeckOfCards.h"
#include "Card.h"

#include <ctime>
#include <cstdlib>
#include <iostream>



DeckOfCards::DeckOfCards() //create the deck of cards so we can access it
{
	int hold = 0;

	for (int index = 0; index < 13; index++)  //create heart cards
	{

		deck[hold++] = Card(index, 0);

	}
	for (int index = 0; index < 13; index++)  //create heart cards
	{

		deck[hold++] = Card(index, 1);

	}

	for (int index = 0; index < 13; index++)  //create diamond
	{
		deck[hold++] = Card(index, 2);
	}

	for (int index = 0; index < 13; index++)  //create spade
	{
		deck[hold++] = Card(index, 3);

	}
}


void DeckOfCards::shuffle()
//swap the two cards with each other
//ex: if a had the card at position 31, and b had card at position 34
//a should have the card at position 34 and b should have the card at position 31
{

	int a;
	int b; // = 0;

	for (int index = 0; index < 52; index++) //shuffle 52 cards
	{

		//referenced: http://www.cplusplus.com/forum/beginner/98214/
		// http://www.cplusplus.com/forum/beginner/26611/
		a = rand() % 52; //see references above
		Card firstSwap = deck[a]; //generated number (a), indexed through 52, stored in that random spot
		b = rand() % 52;
		Card secondSwap = deck[b];//generated number (b), indexed through 52, stored in that random spot
		Card temp = firstSwap; //temp is required: If we do not, we will never be able to swap both cards. Only 1 will get swapped
		deck[a] = secondSwap;
		deck[b] = temp;


	}
}

//give a card
Card DeckOfCards::dealCard()
{

	if (currentCard < 52)
	{

		return (deck[currentCard++]);
	}

}
//check if we have more cards
bool DeckOfCards::moreCards()
{
	if (currentCard < 52)
	{
		return true;
	}
	else
	{
		return false;
	}
}



DeckOfCards::~DeckOfCards()
{
}
