#ifndef PLAYERSBOX_H
#define PLAYERSBOX_H

////////////////////////////////////////////////////////////

// View for displaying all four players

////////////////////////////////////////////////////////////

#include <gtkmm/box.h>

#include "PlayerView.h"
#include "Observer.h"
#include "GameModel.h"
#include "GameController.h"

class PlayersBox : public Gtk::HBox, public Observer {
public:
	PlayersBox ( GameModel*, GameController* );
	virtual ~PlayersBox ();

	void update ();
private:
	GameModel *model_;
	GameController *controller_;

	PlayerView *players_[4];		// Array of 4 players
};

#endif