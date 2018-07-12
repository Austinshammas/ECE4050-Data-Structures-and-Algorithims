// Team Members: Austin Shammas and Mohammad Anwer
//Program is interpreted correctly
//Program produces correct results
//Question 3 Assignment 3

#include "Card.h"
#include "DeckOfCards.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main()
{
	srand(time(0));
	DeckOfCards makeDeck; //create makeDeck object
	makeDeck.shuffle(); //shuffle the cards
	int container[5];
	string cardHolder;
	string secondp[5];
	string secp[5];
	string ace = "Ace";
	string two = "Two";
	string three = "Three";
	string four = "Four";
	string five = "Five";
	string six = "Six";
	string seven = "Seven";
	string eight = "Eight";
	string nine = "Nine";
	string ten = "Ten";
	string Jack = "Jack";
	string Queen = "Queen";
	string King = "King";



	//deal the hand
	for (int c = 0; c < 5; c++)
	{
		secondp[c] = makeDeck.dealCard().getFace();
		secp[c] = makeDeck.dealCard().getSuit();
		cout << secondp[c] << " of " << secp[c] << "\n";
	}

	//convert all face cards to integers so we can compare it when determining if we have a straight
	for (int i = 0; i < 5; i++)
	{
		if (secondp[i] == ace)
		{
			container[i] = 1;

		}
		if (secondp[i] == two)
		{
			container[i] = 2;
		}
		if (secondp[i] == three)
		{
			container[i] = 3;
		}
		if (secondp[i] == four)

		{
			container[i] = 4;
		}
		if (secondp[i] == five)
		{
			container[i] = 5;
		}
		if (secondp[i] == six)
		{
			container[i] = 6;
		}

		if (secondp[i] == seven)
		{
			container[i] = 7;
		}

		if (secondp[i] == eight)
		{
			container[i] = 8;
		}

		if (secondp[i] == nine)
		{
			container[i] = 9;
		}

		if (secondp[i] == ten)
		{
			container[i] = 10;
		}
		if (secondp[i] == Jack)
		{
			container[i] = 11;
		}

		if (secondp[i] == Queen)
		{
			container[i] = 12;
		}

		if (secondp[i] == King)
		{
			container[i] = 13;
		}

	}


	std::sort(container, container + 5); // i referenced this to sort my array:
										 // https://stackoverflow.com/questions/4008253/how-to-sort-c-array-in-asc-and-desc-mode

										 //check for straight
	if (container[0] + 1 == container[1] && container[1] + 1 == container[2] && container[2] + 1 == container[3] && container[3] + 1 == container[4])
		cout << "\nStraight!" << endl;


	//check for a flush
	else if (secp[0] == secp[1] && secp[0] == secp[2] && secp[0] == secp[3] && secp[0] == secp[4])
		cout << "\nFlush!" << endl;


	//check for 4 of a kind
	else if (secondp[0] == secondp[1] && secondp[0] == secondp[2] && secondp[0] == secondp[3] ||
		secondp[0] == secondp[1] && secondp[0] == secondp[2] && secondp[0] == secondp[4] ||
		secondp[0] == secondp[2] && secondp[0] == secondp[3] && secondp[0] == secondp[4] ||
		secondp[0] == secondp[1] && secondp[0] == secondp[3] && secondp[0] == secondp[4] ||
		secondp[1] == secondp[2] && secondp[1] == secondp[3] && secondp[1] == secondp[4])

		cout << "\n4 of a kind!";


	// check for 3 of a kind
	else if (secondp[0] == secondp[1] && secondp[0] == secondp[2] ||
		secondp[0] == secondp[1] && secondp[0] == secondp[3] ||
		secondp[0] == secondp[1] && secondp[0] == secondp[4] ||
		secondp[0] == secondp[3] && secondp[0] == secondp[4] ||
		secondp[0] == secondp[2] && secondp[0] == secondp[4] ||
		secondp[0] == secondp[2] && secondp[0] == secondp[3] ||
		secondp[1] == secondp[2] && secondp[1] == secondp[3] ||
		secondp[1] == secondp[2] && secondp[1] == secondp[4] ||
		secondp[1] == secondp[3] && secondp[1] == secondp[4] ||
		secondp[2] == secondp[3] && secondp[2] == secondp[4])

		cout << "\n3 of a kind" << endl;

	//check for two pairs. this will check all ways 2 pairs can form
	else if (secondp[0] == secondp[1] && secondp[2] == secondp[3] || secondp[0] == secondp[1] && secondp[3] == secondp[4] ||
		secondp[0] == secondp[1] && secondp[4] == secondp[2] ||

		secondp[0] == secondp[2] && secondp[1] == secondp[3] || secondp[0] == secondp[2] && secondp[1] == secondp[4] ||
		secondp[0] == secondp[2] && secondp[3] == secondp[4] ||

		secondp[0] == secondp[3] && secondp[1] == secondp[2] || secondp[0] == secondp[3] && secondp[1] == secondp[4] ||
		secondp[0] == secondp[3] && secondp[2] == secondp[4] ||

		secondp[0] == secondp[4] && secondp[1] == secondp[2] || secondp[0] == secondp[4] && secondp[1] == secondp[3] ||
		secondp[0] == secondp[4] && secondp[2] == secondp[3] ||

		secondp[1] == secondp[2] && secondp[3] == secondp[4] || secondp[1] == secondp[2] && secondp[0] == secondp[4] ||
		secondp[1] == secondp[3] && secondp[2] == secondp[4])

		cout << "\n 2 Pair" << endl;


	// check for a pair . this will check all ways a pair can form
	else if


		(secondp[0] == secondp[1] || secondp[0] == secondp[2] || secondp[0] == secondp[3] || secondp[0] == secondp[4] ||

			secondp[1] == secondp[2] || secondp[1] == secondp[3] || secondp[1] == secondp[4] ||

			secondp[2] == secondp[3] || secondp[2] == secondp[4] ||

			secondp[3] == secondp[4])

		cout << "1 pair" << endl;

	else
		cout << "Your hand does not have any pairs, cards of the same kind, a flush or a straight." << endl;

	system("PAUSE");
	return 0;
}