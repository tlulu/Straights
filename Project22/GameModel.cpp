#include "GameModel.h"

GameModel::GameModel () {
	// default seed = 0
	gameSeed_ = 0;

	// default starting player
	currentPlayer_ = 0;

	// initialize all players as robots
	for (int i = 0; i < 4; i ++) {
		players_.push_back (new ComputerPlayer (i));
	}

	// Initialize deck and board
	deck_ = new Deck ();
	board_ = new Board ();

	currentSelectedCard_ = NULL;

	gameInProgress_ = false;

	turnCount_ = 0;
}

GameModel::~GameModel () {
	// delete players
	for (int i=0; i<4; i++) {
		delete players_[i];
	}

	// delete deck and board
	delete deck_;
	delete board_;

	if (currentSelectedCard_ != NULL) {
		delete currentSelectedCard_;
	}
}

void GameModel::subscribe ( Observer *view ) {
	views_.insert (view);
}

void GameModel::unsubscribe ( Observer *view ) {
	views_.erase (view);
}

void GameModel::notify () {
	std::set<Observer*>::iterator i;
	for ( i = views_.begin(); i != views_.end(); ++i ) {
		(*i) -> update();
	}
}

std::vector<Player*> GameModel::winningPlayers () {
	std::vector<Player*> players;
	Player* minScorePlayer = players_[0];
	bool allowWin = false;
	for ( int i=0; i<4; i++ ) {
		Player* currentPlayer = players_[i];
		if ( currentPlayer->totalScore () >= 80 ) {
			allowWin = true;							// Can only win when someone has a score of >= 80
		}
		if ( currentPlayer->totalScore () < minScorePlayer->totalScore () ) {
			minScorePlayer = currentPlayer;				// Keep track of the player with the lowest score
		}
	}

	if (allowWin) {
		for ( int i=0; i<4; i++ ) {
			if ( players_[i] -> totalScore() == minScorePlayer -> totalScore() ){
				players.push_back(players_[i]);
			}
		}
		notify();
	}

	return players;
}

void GameModel::reset () {
	board_ -> clear ();
	for (int i=0; i<4; i++) {
		players_[i]->refreshPlayer();				// Get the player ready for the next round
	}

	notify();
}

int GameModel::turnCount() const {
	return turnCount_;
}

void GameModel::changeCurrentPlayerToComputer () {
	Player *p = players_[currentPlayer_];
	players_[currentPlayer_] = new ComputerPlayer ( *p );
	delete p;

	notify ();
}

void GameModel::changeComputerToHuman ( int index ) {
	Player *p = players_[index];
	players_[index] = new HumanPlayer ( *p );
	delete p;

	notify ();
}

int GameModel::nextPlayer () {
	currentPlayer_ ++;
	currentPlayer_ = currentPlayer_ % 4;

	notify ();

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

	notify ();
}

bool GameModel::currentPlayerIsComputer () const {
	return !players_[currentPlayer_] -> playable ();
}

void GameModel::takeTurnForCurrentPlayer () {
	players_[currentPlayer_] -> takeTurn ( *deck_, *board_ );

	notify ();
}

void GameModel::playCard () {
	Card card = *currentSelectedCard_;
	players_[currentPlayer_] -> play (card, *board_);

	currentSelectedCard_ = NULL;
	turnCount_++;
	notify ();
}

void GameModel::discardCard () {
	Card card = *currentSelectedCard_;
	players_[currentPlayer_] -> discard (card);

	currentSelectedCard_ = NULL;
	turnCount_++;
	notify ();
}

bool GameModel::canPlayCard () const {
	if (currentSelectedCard_ == NULL) {
		return false;
	}
	Card card = *currentSelectedCard_;
	Hand h = players_[currentPlayer_] -> getLegalPlays (*deck_, *board_);
	return h.hasCard (card);
}

bool GameModel::canDiscardCard () const {
	if (currentSelectedCard_ == NULL) {
		return false;
	}
	Card card = *currentSelectedCard_;
	Hand h = players_[currentPlayer_] -> getLegalPlays (*deck_, *board_);
	return h.size() == 0;
}

Card* GameModel::currentSelectedCard () const {
	return currentSelectedCard_;
}

void GameModel::setCurrentSelectedCard ( int index ) {
	delete currentSelectedCard_;
	Card card = players_[currentPlayer_] -> cardInHand ( index );
	currentSelectedCard_ = new Card (card.getSuit(), card.getRank());

	notify ();
}

void GameModel::shuffle () {
	deck_ -> shuffle ( gameSeed_ );

	notify ();
}

void GameModel::dealCardToPlayers () {
	for (int i=0; i<4; i++) {
		for (int j=0; j<13; j++) {
			players_[i]->addCard ( deck_->cardAt (13 * i + j) );
		}
	}

	notify ();
}

int GameModel::scoreForPlayer ( int index ) const {
	return players_[index] -> totalScore ();
}

int GameModel::seed () const {
	return gameSeed_;
}

void GameModel::setSeed ( int seed ) {
	gameSeed_ = seed;

	notify ();
}

Board* GameModel::board () const {
	return board_;
}

Hand* GameModel::handForPlayer ( int index ) const {
	return players_[index] -> hand ();
}

Hand* GameModel::discardedHandForPlayer ( int index ) const {
	return players_[index] -> discardedHand ();
}

bool GameModel::playerIsComputer ( int index ) const {
	return players_[index] -> playable ();
}

bool GameModel::isGameInProgress () const {
	return gameInProgress_;
}

void GameModel::setGameInProgress (bool b) {
	gameInProgress_ = b;
}

