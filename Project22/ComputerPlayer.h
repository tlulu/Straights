#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include "Player.h"

/********************************************************

Computer Player ADT, inherited from Player, acts automatically

********************************************************/

class ComputerPlayer : public Player {
public:
	ComputerPlayer (int);						// Constructor, pass in id
	virtual ~ComputerPlayer ();					// Destructor
	ComputerPlayer (const Player&);				// Copy constructor

	bool playable () const;

	TurnResult takeTurn (const Deck&, Board&) ;	// Computer chooses what to play
};

#endif