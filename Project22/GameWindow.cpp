#include <gtkmm/stock.h>
#include <iostream>

#include "GameWindow.h"
#include "Card.h"

GameWindow::GameWindow () : length_(480), width_(400) {

	set_default_size (length_, width_);

	gameModel_ = new GameModel ();
	gameController_ = new GameController ( gameModel_ );

	tableView_ = new CardTableView ( gameModel_, gameController_ );
	handView_ = new HandView ( gameModel_, gameController_ );
	gamePanelView_ = new GamePanelView( gameModel_, gameController_ );
	playerView_ = new PlayerView( gameModel_, gameController_ );

	gameModel_ -> subscribe ( tableView_ );
	gameModel_ -> subscribe ( playerView_ );
	gameModel_ -> subscribe ( handView_ );

	container_.add ( *gamePanelView_ );	
	container_.add ( *tableView_ );
	container_.add ( *playerView_);
	container_.add ( *handView_ );

	add (container_);

	show_all ();
}

GameWindow::~GameWindow () {
	delete gameModel_;
	delete gameController_;
	delete tableView_;
	delete gamePanelView_;
	delete handView_;
	delete playerView_;
}