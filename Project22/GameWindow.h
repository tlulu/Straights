#ifndef GTKMM_GAMEWINDOW_H
#define GTKMM_GAMEWINDOW_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/table.h>
#include <gtkmm/image.h>

#include "GameModel.h"
#include "GameController.h"

#include "CardTableView.h"
#include "HandView.h"
#include "GamePanelView.h"
#include "PlayersBox.h"

class GameWindow : public Gtk::Window {
public:
	GameWindow ();
	virtual ~GameWindow ();

private:
	const int length_;
	const int width_;

	GameModel *gameModel_;
	GameController *gameController_;

	Gtk::VBox container_;
	CardTableView *tableView_;
	HandView *handView_;
	GamePanelView *gamePanelView_;

	PlayersBox *playersBox_;
};

#endif