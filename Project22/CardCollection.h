#ifndef CARDCOLLECTION_H
#define CARDCOLLECTION_H

#include "Card.h"

#include <vector>

/********************************************************

Interface design using vector for a collection of cards
Base class for Deck, Hand, Board

********************************************************/

class CardCollection {
public:
	CardCollection();					// Constructor
	virtual ~CardCollection();			// Destructor

	bool hasCard(const Card&) const;	// Check of the collection contains card
	Card cardAt(int) const;				// Return the card at index
	void addCard (Card);				// Remove a card from the collection
	void removeCard (Card);				// Add a card to the end of the collection
	void swapCard (int, int);			// Switch the position of 2 cards
	int size () const;					// Return the size of the collection
	void clear();						// Empty the collection

private:
	std::vector<Card> cards_;
};

#endif
