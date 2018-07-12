#include "Card.h"
#include <string>

#include <ctime>
#include <cstdlib>
using namespace std;
Card::Card()

{
}


const string Card::cardface[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
const string Card::cardsuit[4] = { "Club", "Heart", "Diamond", "Spade" };


Card::Card(int x, int y)
{

	face = cardface[x];//[x]; // set face to the facecard at X
	suit = cardsuit[y];//[y]; //set suit to the card's suit at Y 
					   //face and suit have correct values here


}

string Card::getFace() //part d 
{
	return face; 

}


string Card::getSuit() //part d 
{

	return suit;

}

string Card::toString() //part d 
{
	return Card::face + " of " + Card::suit; //part d says to use this exact line

}

Card::~Card()
{
}