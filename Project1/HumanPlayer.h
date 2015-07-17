#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"

/*************************************************************************

Human Player, inherited from Player, acts based on command

*************************************************************************/

class HumanPlayer : public Player {
public:
	class PlayerException {									// Base exception from player
	public:
		PlayerException ();
		~PlayerException ();

		virtual std::string message () const = 0;			// Virtual method for the exception message
	};

	class IllegalPlayException : public PlayerException{	// Play a illegal card exception
	public:
		IllegalPlayException ();
		~IllegalPlayException ();

		std::string message () const;
	};

	class IllegalDiscardException : public PlayerException{	// Discard a with there is a legal play exception
	public:
		IllegalDiscardException ();
		~IllegalDiscardException ();

		std::string message () const;
	};

	HumanPlayer (int);										// Constructor, takes the player id
	virtual ~HumanPlayer ();								// Destructor
	HumanPlayer (const Player&);							// Copy contructor

	TurnResult takeTurn (const Deck&, Board&);				// Player takes turn, returns the status of the turn
protected:
	void play(Card, Board&, const Hand&);					// Play a card
	void discard(Card, const Hand&);						// Discards a card
};

#endif