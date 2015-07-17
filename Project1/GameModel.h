#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include <set>

#include "Player.h"
#include "Deck.h"
#include "Board.h"
#include "Card.h"
#include "View.h"

class GameModel {
public:
	GameModel ();
	virtual ~GameModel ();

	void subscribe ( View* );
	void unsubscribe ( View* );

	// Players
	void addHumanPlayer ( int );
	void changeHumanToComputer ( int ); //computerify
	void changeComputerToHuman ( int );
	int nextPlayer ();
	int currentPlayer () const; 

	// Card
	void playCard ( const Card );
	void discardCard ( const Card );
	void shuffle ();

	// Score
	int scoreForPlayer ( int );

	// Seed
	int seed () const;
	void setSeed ( int );

	// Board
	Board* board () const;

	// Hand
	Hand* handForCurrentPlayer () const;
private:
	void notify ();

	std::set<View*> views_;

	int gameSeed_;

	int currentPlayer_;

	std::vector<Player*> players_;
	Deck *deck_;
	Board *board_;
};

#endif