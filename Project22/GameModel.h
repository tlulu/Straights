#ifndef GAMEMODEL_H
#define GAMEMODEL_H

////////////////////////////////////////////////////////////

// Model for the game using facade pattern

////////////////////////////////////////////////////////////

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

	void subscribe ( Observer* );	// Subscribe views
	void unsubscribe ( Observer* );	// Unsubscribe views

	void reset();				// Reset the round
	int turnCount() const;		// Return the number of turns passed

	// Players
	void changeCurrentPlayerToComputer (); 		// For ragequits
	void changeComputerToHuman ( int );			// For join game
	int nextPlayer ();							// Go to the next player
	int currentPlayer () const; 				// The the current player
	void setCurrentPlayer ();					
	bool currentPlayerIsComputer () const;		// Check if current player is computer
	void takeTurnForCurrentPlayer ();			// For computer players to take turn
	std::vector<Player*> winningPlayers ();		// Get all the winners

	// Card
	void playCard ();							// Human player plays card
	void discardCard ();						// Human player discards card
	bool canPlayCard () const;					// Check if a human player can play card
	bool canDiscardCard () const;				// Check if a human player can discard card
	void shuffle ();							// Shuffle the deck
	void dealCardToPlayers ();					// Deal cards to all players

	Card* currentSelectedCard () const;			// Get the card that is currently selected
	void setCurrentSelectedCard ( int );		

	// Score
	int scoreForPlayer ( int ) const;			// Get the score for a player

	// Seed
	int seed () const;							// Get the current game seed
	void setSeed ( int );

	// Board
	Board* board () const;						// Get the board

	// Hand
	Hand* handForPlayer ( int ) const;			// Get the hand for a player
	Hand* discardedHandForPlayer ( int ) const; // Get the discarded hand for a player
	bool playerIsComputer ( int ) const;		// Check if a player is computer

	bool isGameInProgress () const;				// Check if the game has started
	void setGameInProgress (bool);

	void refreshWithSeed ( int );				// Create a new game with a new seed

	std::string discardedCardForPlayer ( int index ) const; // Return the discarded cards for a player as a string
private:
	void notify ();				// notify to update the views
	void notifyEndRound ();		// notify to show dialog box

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