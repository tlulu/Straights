#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Player.h"
#include "HumanPlayer.h"
#include "Card.h"
#include "Deck.h"
#include "Board.h"
#include "CardCollection.h"

/********************************************************

Game Controller to manage the game
Manages:
	- Players
	- Deck
	- Board
	- Game flow

********************************************************/

#include <vector>

class GameController {
public:
	GameController (int, int);					// Constructor, pass in the number of players, and the game random seed
	virtual ~GameController ();					// Destructor

	void startGame ();							// Start a new game
private:
	int numPlayers_;							// Number of players
	int gameSeed_;								// Game seed

	std::vector<Player*> players_;				// Players
	Deck deck_;									// Deck
	Board board_;								// Board

	int beginRound (); 							// Start a new round, return 1 if round is successful, return 0 if a player quits
	void endRound ();							// Do some clean up when ending the round

	void dealCards ();							// Deal cards to the player
	Player* playerWithCard (const Card&);		// Get the player that has a specific card, returns NULL is not found
	Player* nextPlayer (const Player*);			// Get the next player in the rotation 
	Player* computerify (HumanPlayer*);			// Change a human player to computer
	Player* winningPlayer ();					// Find the player that won, return NULL if no one won
};

#endif