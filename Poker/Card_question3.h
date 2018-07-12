#pragma once
#include <iostream>

#include <string>

using namespace std;
class Card
{
public:
	//initialization
	Card();
	Card(int cardface, int cardsuit);
	string toString();
	string getSuit();
	string getFace();
	const static string cardface[13];
	const static string cardsuit[4];
	int x, y;
	string face;
	string suit;
	~Card();
};


