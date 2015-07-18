#include <gtkmm/stock.h>
#include <iostream>

#include "GameWindow.h"
#include "Card.h"

GameWindow::GameWindow () : length_(480), width_(400) {

	set_default_size (length_, width_);

	tableModel_ = new CardTableModel ();
	tableController_ = new CardTableController ( tableModel_ );
	tableView_ = new CardTableView ( tableModel_, tableController_ );

	tableModel_ -> subscribe ( tableView_ );

	handModel_ = new HandModel ();
	handController_ = new HandController ( handModel_ );
	handView_ = new HandView ( handModel_, handController_ );

	handModel_ -> subscribe ( handView_ );

	gamePanelView_ = new GamePanelView();
	playerView_ = new PlayerView();

	vBox.add ( *gamePanelView_ );	
	vBox.add ( *tableView_ );
	vBox.add ( *playerView_);
	vBox.add ( *handView_ );

	add (vBox);

	show_all ();
}

GameWindow::~GameWindow () {
	delete tableModel_;
	delete tableController_;
	delete tableView_;
	delete gamePanelView_;
}