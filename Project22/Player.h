#ifndef _PLAYER_
#define _PLAYER_

#include <iostream>

#include "Hand.h"
#include "Deck.h"
#include "Board.h"

/*************************************************************************

Player ADT
Base class for HumanPlayer, ComputerPlayer

Manages:
	- Player's turn
	- Player's hand
	- Player's discarded cards
	- Player's score

*************************************************************************/

// Result at the end of each turn
enum TurnResult {
	Nothing, 
	Quit, 			
	RageQuit
};

class Player {
public:
	Player (int);												// Constructor
	virtual ~Player ();											// Destructor
	Player (const Player&);										// Copy constructor

	int id () const;											// Player id
	int currentScore () const;									// Player score for current round
	int totalScore() const;										// Player total score
	void refreshPlayer ();										// Prepare player for next round
	bool hasCard (const Card&) const;							// Check if player has a card
	void addCard (Card);										// Add card to player's hand

	void printDiscardedHand () const;							// Display the discarded hand
	void printScore () const;									// Display player's score

	Hand* hand ();
	Hand* discardedHand ();

	virtual bool playable () const = 0;

	Hand getLegalPlays (const Deck&, const Board&) const;		// Return all the legal plays a player can make
	virtual void play(Card, Board&);				// Player plays a card, can override for additional features
	virtual void discard(Card);					// Player discards a card, can override for additional features

	virtual TurnResult takeTurn (const Deck&, Board&) = 0;		// A turn for the player, return the result of the turn

protected:
	void addScore( int score );									// Add the current score to player's total score, reset current score
	Hand currentHand () const;									// Return player's current hand

private:
	int id_;													// id
	int currentScore_;											// score for current round
	int totalScore_;											// score for the whole game

	Hand currentHand_;											// current hand
	Hand discardedHand_;										// discarded cards
};

std::ostream& operator<< (std::ostream&, const Player&);		// output format: player <id_>

#endif