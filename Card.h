#ifndef _CARD_
#define _CARD_

#include <ostream>
#include <istream>

enum Suit { CLUB, DIAMOND, HEART, SPADE, SUIT_COUNT };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT };

class Card{
	friend std::istream &operator>>(std::istream &, Card &);

public:
	Card(Suit, Rank);										// Constructor
	Suit getSuit() const;									// Return the suit
	Rank getRank() const;									// Return the rank
	std::string getRankString() const;						// Return the rank as a string for displaying
	int getScore() const;									// Return the score this card represents
	
private:
	Suit suit_;
	Rank rank_;
};

bool operator==(const Card &, const Card &);				// Equality
bool operator< (const Card &, const Card &);				// Less than for comparing

//output/input Card in the format <rank><suit>
std::ostream &operator<<(std::ostream &, const Card &);		// Write
std::istream &operator>>(std::istream &, Card &);			// Read

#endif
