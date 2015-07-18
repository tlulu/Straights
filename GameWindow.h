#ifndef GTKMM_GAMEWINDOW_H
#define GTKMM_GAMEWINDOW_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/table.h>
#include <gtkmm/image.h>

#include "CardTableView.h"
#include "CardTableModel.h"
#include "CardTableController.h"

#include "HandView.h"
#include "HandModel.h"
#include "HandController.h"

#include "GamePanelView.h"
#include "PlayerView.h"

class GameWindow : public Gtk::Window {
public:
	GameWindow ();
	virtual ~GameWindow ();

private:
	const int length_;
	const int width_;

	CardTableModel *tableModel_;
	CardTableView *tableView_;
	CardTableController *tableController_;

	HandModel *handModel_;
	HandView *handView_;
	HandController *handController_;

	Gtk::VBox vBox;
	PlayerView *playerView_;
	GamePanelView *gamePanelView_;
};

#endif