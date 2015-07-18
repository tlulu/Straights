#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include <set>

#include "Player.h"
#include "Deck.h"
#include "Board.h"
#include "Card.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
//#include "View.h"

class GameModel {
public:
	GameModel ();
	virtual ~GameModel ();

	//void subscribe ( View* );
	//void unsubscribe ( View* );

	// Players
	void changeCurrentPlayerToComputer (); //computerify
	void changeComputerToHuman ( int );
	int nextPlayer ();
	int currentPlayer () const; 
	void setCurrentPlayer ();
	bool currentPlayerIsComputer () const;
	void takeTurnForCurrentPlayer ();

	// Card
	void playCard ( const Card );
	void discardCard ( const Card );
	bool canPlayCard ( const Card ) const;
	bool canDiscardCard ( const Card ) const;
	void shuffle ();
	void dealCardToPlayers ();

	// Score
	int scoreForPlayer ( int ) const;

	// Seed
	int seed () const;
	void setSeed ( int );

	// Board
	Board* board () const;

	// Hand
	Hand* handForPlayer ( int ) const;
private:
	//void notify ();

	//std::set<View*> views_;

	int gameSeed_;

	int currentPlayer_;

	std::vector<Player*> players_;
	Deck *deck_;
	Board *board_;
};

#endif