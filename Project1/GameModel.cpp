#include "GameModel.h"

GameModel::GameModel () {

}

GameModel::~GameModel () {

}

void GameModel::subscribe ( View *view ) {
	views_.push_back (view);
}

void GameModel::unsubscribe ( View *view ) {
	views_.erase (view);
}

void GameModel::notify () {
	std::set<View*>::iterator i;
	for ( i = observers_.begin(); i != views_.end(); ++i ) {
		(*i) -> update();
	}
}

void GameModel::startGame ( int seed ) {
	gameSeed_ = seed;

	
}

void GameModel::makePlayerHuman ( int index ) {

}

void GameModel::makePlayerComputer ( int index ) {

}

void GameModel::playCard ( const Card c ) {

}