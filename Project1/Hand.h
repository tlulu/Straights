#ifndef HAND_H
#define HAND_H

#include "CardCollection.h"

/************************************************************************

Hand ADT inherited from Card Collection
Used as cards held by players

************************************************************************/

class Hand : public CardCollection{
public:
	Hand();												// Constructor
	virtual ~Hand();									// Destructor
};

std::ostream& operator<< (std::ostream&, const Hand&);	// Output

#endif