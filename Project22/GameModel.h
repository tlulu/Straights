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

	void reset();
	int turnCount() const;

	// Players
	void changeCurrentPlayerToComputer (); //computerify
	void changeComputerToHuman ( int );
	int nextPlayer ();
	int currentPlayer () const; 
	void setCurrentPlayer ();
	bool currentPlayerIsComputer () const;
	void takeTurnForCurrentPlayer ();
	std::vector<Player*> winningPlayers ();

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
	Hand* discardedHandForPlayer ( int ) const;
	bool playerIsComputer ( int ) const;

	bool isGameInProgress () const;
	void setGameInProgress (bool);

	void refreshWithSeed ( int );

	std::string discardedCardForPlayer ( int index ) const;
private:
	void notify ();
	void notifyEndRound ();

	std::set<Observer*> views_;

	int gameSeed_;

	int currentPlayer_;

	std::vector<Player*> players_;
	Deck *deck_;
	Board *board_;

	Card *currentSelectedCard_;

	bool gameInProgress_;

	int turnCount_;
};

#endif