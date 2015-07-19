#ifndef DECK_H
#define DECK_H

#include "CardCollection.h"

/********************************************************

Deck ADT inherited from CardCollection

********************************************************/

class Deck : public CardCollection{
public:
	Deck ();											// Constructor
	virtual ~Deck ();									// Destructor

	void shuffle (int);									// Randomly shuffles the deck using a seed
	void reset ();
};

std::ostream& operator<< (std::ostream&, const Deck&);	// Output

#endif
