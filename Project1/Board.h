#ifndef BOARD_H
#define BOARD_H

// Board class for tracking played cards

#include "CardCollection.h"

#include <vector>
#include <iostream>

/********************************************************

Board ADT inherited from CardCollection

********************************************************/

class Board : public CardCollection{
public:
	Board();												// Constructor
	virtual ~Board();										// Destructor

	bool isLegalPlay(const Card& card) const;				// Check if a card can be played on the board
};

std::ostream& operator<< (std::ostream&, const Board&);		// Output stream

#endif