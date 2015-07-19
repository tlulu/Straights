#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"

/*************************************************************************

Human Player, inherited from Player, acts based on command

*************************************************************************/

class HumanPlayer : public Player {
public:
	HumanPlayer (int);										// Constructor, takes the player id
	virtual ~HumanPlayer ();								// Destructor
	HumanPlayer (const Player&);							// Copy contructor

	bool playable () const;						// Determine if the player can be controlled by human

	void play(Card, Board&);					// Play a card
	void discard(Card);						// Discards a card

	TurnResult takeTurn (const Deck&, Board&);				// Player takes turn, returns the status of the turn
};

#endif