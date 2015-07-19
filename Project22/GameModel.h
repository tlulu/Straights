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
#include "Observer.h"

class GameModel {
public:
	GameModel ();
	virtual ~GameModel ();

	void subscribe ( Observer* );
	void unsubscribe ( Observer* );

	// Players
	void changeCurrentPlayerToComputer (); //computerify
	void changeComputerToHuman ( int );
	int nextPlayer ();
	int currentPlayer () const; 
	void setCurrentPlayer ();
	bool currentPlayerIsComputer () const;
	void takeTurnForCurrentPlayer ();

	// Card
	void playCard ();
	void discardCard ();
	bool canPlayCard () const;
	bool canDiscardCard () const;
	void shuffle ();
	void dealCardToPlayers ();

	Card* currentSelectedCard () const;
	void setCurrentSelectedCard ( int );

	// Score
	int scoreForPlayer ( int ) const;

	// Seed
	int seed () const;
	void setSeed ( int );

	// Board
	Board* board () const;

	// Hand
	Hand* handForPlayer ( int ) const;
	//Card selectedCard () const; 
private:
	void notify ();

	std::set<Observer*> views_;

	int gameSeed_;

	int currentPlayer_;
	//Card *selectedCard_;

	std::vector<Player*> players_;
	Deck *deck_;
	Board *board_;

	Card *currentSelectedCard_;
};

#endif