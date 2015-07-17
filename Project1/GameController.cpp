#include "GameController.h"
#include "ComputerPlayer.h"

#include <iostream>

//************************************************************************
//* IMPLENTATION OF GAMECONTROLLER
//************************************************************************

//************************************************************************
//* Private Methods
//************************************************************************

// Deal cards to each player in chunks of 13
void GameController::dealCards () {
	for (int i=0; i<numPlayers_; i++) {
		for (int j=0; j<13; j++) {
			players_[i]->addCard ( deck_.cardAt (13 * i + j) );
		}
	}
}

// Find the player with a specific card, returns NULL if not found
Player* GameController::playerWithCard (const Card &card) {
	for (int i=0; i<numPlayers_; i++) {
		Player* player = players_[i];
		if ( player->hasCard (card) ) {
			return player;
		}
	}

	return NULL;
}

// Get the next player in the rotation
Player* GameController::nextPlayer (const Player* currentPlayer) {
	int id = currentPlayer->id ();
	int nextId = id % numPlayers_ + 1;
	return players_[nextId-  1];
}

// Change a human to computer
Player* GameController::computerify (HumanPlayer* humanPlayer) {
	ComputerPlayer *p = new ComputerPlayer (*humanPlayer);
	players_[humanPlayer->id() - 1] = p;
	delete humanPlayer;

	return p;
}

// Get the winning player, return NULL if no one wins

// Win condition:
//	- A player must have a score of over 80
//	- Player with the lowest score wins
Player* GameController::winningPlayer () {
	Player* minScorePlayer = players_[0];
	bool allowWin = false;
	for ( int i=0; i<numPlayers_; i++ ) {
		Player* currentPlayer = players_[i];
		if ( currentPlayer->totalScore () >= 80 ) {
			allowWin = true;							// Can only win when someone has a score of >= 80
		}
		if ( currentPlayer->totalScore () < minScorePlayer->totalScore () ) {
			minScorePlayer = currentPlayer;				// Keep track of the player with the lowest score
		}
	}

	if (allowWin) {
		return minScorePlayer;
	} else {
		return NULL;
	}
}

// Constructor
GameController::GameController (int numPlayers, int seed) : numPlayers_(numPlayers), gameSeed_(seed) {}

// Destructor
GameController::~GameController () {
	// Destory all player objects
	for (int i=0;i<numPlayers_;i++){
		delete players_[i];
	}
}

// Game starts
void GameController::startGame () {
	// Prompt for human or computer players
	for (int i=1; i<=numPlayers_; i++) {
		std::cout << "Is player " << i << " a human(h) or a computer(c)?" << std::endl;
		char type;
		std::cout << ">";
		std::cin >> type;

		Player *p;
		if (type == 'h') {
			p = new HumanPlayer(i);
		} else {
			p = new ComputerPlayer(i);
		}
		players_.push_back(p);
	}

	// Keep starting round until a winner is found
	Player *winner = NULL;
	while ( winner == NULL ) {
		bool successRound = beginRound ();
		if ( !successRound ) { 
			// A player decided to quit mid game, game terminates
			return;
		}

		winner = winningPlayer ();
	}

	// Display the winner, quit game
	std::cout << "Player " << winner->id () << " wins!" << std::endl;
}

// Begin a new round
int GameController::beginRound () {
	// Shuffle the deck using the game seed
	deck_.shuffle (gameSeed_);
	// Deal cards to each player
	dealCards (); 

	// Find the player with 7S
	Player *currentPlayer = playerWithCard (Card (SPADE, SEVEN));

	std::cout << "A new round begins. It's " << *currentPlayer << "'s turn to play." << std::endl;

	// Each round lasts 52 turns
	for (int i=0; i<52; i++) {
		// Get the result of each turn
		TurnResult result = currentPlayer -> takeTurn (deck_, board_);
		switch (result) {
			case Quit:		// A player quits the game, terminate the round with a fail status
				return 0;
			case RageQuit:	// A player rage quits, replace that player with a computer, redo the turn
				std::cout << "Player " << currentPlayer->id() << " ragequits. A computer will now take over." << std::endl;
				currentPlayer = computerify ((HumanPlayer *)currentPlayer);
				i--;
				break;
			default:		// Turn ended normally, go to the nextt player's turn
				currentPlayer = nextPlayer (currentPlayer);
				break;
		}
	}

	// Clean up before starting a new round
	endRound ();

	// Round ended successfully
	return 1;
}

// Clean up at the end of each round
void GameController::endRound () {
	// Empty the board
	board_.clear ();
	for (int i=0; i<numPlayers_; i++) {
		Player *currentPlayer = players_[i];
		currentPlayer->printDiscardedHand ();	// Print the discarded hand
		currentPlayer->printScore ();			// Print the total score + current score
		currentPlayer->refreshPlayer();			// Get the player ready for the next round
	}
}