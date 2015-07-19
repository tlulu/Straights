#include "PlayersBox.h"

PlayersBox::PlayersBox (GameModel* model, GameController *controller) : model_ (model), controller_ (controller) {
	for (int i=0; i<4; i++) {
		players_[i] = new PlayerView ( model_, controller_ , i);
		add (*players_[i]);
	}

	show_all();
}

PlayersBox::~PlayersBox () {
	for (int i=0; i<4; i++) {
		delete players_[i];
	}
}

void PlayersBox::update () {
	for (int i=0; i<4; i++) {
		players_[i] -> update();
	}
}

