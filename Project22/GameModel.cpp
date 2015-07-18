#include "GameModel.h"

GameModel::GameModel () {
	// default seed = 0
	gameSeed_ = 0;

	// default starting player
	currentPlayer_ = 0;

	// initialize all players as robots
	for (int i = 0; i < 4; i ++) {
		players_[i] = new ComputerPlayer (i);
	}

	// Initialize deck and board
	deck_ = new Deck ();
	board_ = new Board ();
}

GameModel::~GameModel () {
	// delete players
	for (int i=0; i<4; i++) {
		delete players_[i];
	}

	// delete deck and board
	delete deck_;
	delete board_;
}

// void GameModel::subscribe ( View *view ) {
// 	views_.push_back (view);
// }

// void GameModel::unsubscribe ( View *view ) {
// 	views_.erase (view);
// }

// void GameModel::notify () {
// 	std::set<View*>::iterator i;
// 	for ( i = observers_.begin(); i != views_.end(); ++i ) {
// 		(*i) -> update();
// 	}
// }

void GameModel::changeCurrentPlayerToComputer () {
	Player *p = players_[currentPlayer_];
	players_[currentPlayer_] = new ComputerPlayer ( *p );
	delete p;
}

void GameModel::changeComputerToHuman ( int index ) {
	Player *p = players_[index];
	players_[index] = new HumanPlayer ( *p );
	delete p;
}

int GameModel::nextPlayer () {
	currentPlayer_ ++;
	currentPlayer_ = currentPlayer_ % 4;

	return currentPlayer_;
}

int GameModel::currentPlayer () const {
	return currentPlayer_;
}

void GameModel::setCurrentPlayer () {
	Card c ( SPADE, SEVEN );
	for (int i=0; i<4; i++) {
		Player* player = players_[i];
		if ( player->hasCard (c) ) {
			currentPlayer_ = i;
		}
	}
}

bool GameModel::currentPlayerIsComputer () const {
	return players_[currentPlayer_] -> playable ();
}

void GameModel::takeTurnForCurrentPlayer () {
	players_[currentPlayer_] -> takeTurn ( *deck_, *board_ );
}

void GameModel::playCard ( const Card card ) {
	players_[currentPlayer_] -> play (card, *board_);
}

void GameModel::discardCard ( const Card card ) {
	players_[currentPlayer_] -> discard (card);
}

bool GameModel::canPlayCard ( const Card card ) const {
	Hand h = players_[currentPlayer_] -> getLegalPlays (*deck_, *board_);
	return h.hasCard (card);
}

bool GameModel::canDiscardCard ( const Card card ) const {
	Hand h = players_[currentPlayer_] -> getLegalPlays (*deck_, *board_);
	return h.size() == 0;
}

void GameModel::shuffle () {
	deck_ -> shuffle ( gameSeed_ );
}

void GameModel::dealCardToPlayers () {
	for (int i=0; i<4; i++) {
		for (int j=0; j<13; j++) {
			players_[i]->addCard ( deck_->cardAt (13 * i + j) );
		}
	}
}

int GameModel::scoreForPlayer ( int index ) const {
	return players_[index] -> totalScore ();
}

int GameModel::seed () const {
	return gameSeed_;
}

void GameModel::setSeed ( int seed ) {
	gameSeed_ = seed;
}

Board* GameModel::board () const {
	return board_;
}

Hand* GameModel::handForPlayer ( int index ) const {
	return players_[index] -> hand ();
}