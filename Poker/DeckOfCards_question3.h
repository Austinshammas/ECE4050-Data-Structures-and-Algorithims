#pragma once
#include "Card.h"

class DeckOfCards
{
public:
	//initialization 
	DeckOfCards();
	void shuffle();
	Card dealCard();
	bool moreCards();
	Card deck[52];
	~DeckOfCards();
	int currentCard = 0;
};

