#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

////////////////////////////////////////////////////////////

// Controller for the game 

////////////////////////////////////////////////////////////

#include "GameModel.h"
#include "Card.h"

class GameController {
public:
	class GameException {									// Base exception from controller
	public:
		GameException ();
		~GameException ();

		virtual std::string message () const = 0;			// Virtual method for the exception message
	};

	class IllegalPlayException : public GameException{	// Play a illegal card exception
	public:
		IllegalPlayException ();
		~IllegalPlayException ();

		std::string message () const;
	};

	class IllegalDiscardException : public GameException{	// Discard a with there is a legal play exception
	public:
		IllegalDiscardException ();
		~IllegalDiscardException ();

		std::string message () const;
	};

	GameController ( GameModel* );
	virtual ~GameController ();

	void joinGame ( int );				// Player joins the game
	void startGame ();					// Game starts
	void newGame ( int );				// Create new game

	void playCard ();					// Player plays card
	void selectCardToPlay ( int );		// Player picked a card
	void discardCard ();				// Player discards a card
	void rageQuit ();					// Player rage quits

private:
	void computerTurnLoop ();			// Computer takes turn
	bool endRound ();					// Check if a round ended

	GameModel *model_;
};

#endif