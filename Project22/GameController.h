#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "GameModel.h"
#include "Card.h"

class GameController {
public:
	class GameException {									// Base exception from player
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

	void joinGame ( int );
	void startGame ();

	void playCard ( const Card );
	void discardCard (const Card );
	void rageQuit ();

private:
	GameModel *model_;
};

#endif