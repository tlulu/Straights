#include <gtkmm/stock.h>
#include <iostream>
#include <sstream>
#include <vector>

#include "GameWindow.h"
#include "DialogBox.h"

GameWindow::GameWindow () : length_(560), width_(500) {

	set_default_size (length_, width_);


	// Set up the model, views, and controller
	gameModel_ = new GameModel ();
	gameController_ = new GameController ( gameModel_ );

	tableView_ = new CardTableView ( gameModel_, gameController_ );
	handView_ = new HandView ( gameModel_, gameController_ );
	gamePanelView_ = new GamePanelView( gameModel_, gameController_ );
	playersBox_ = new PlayersBox (gameModel_, gameController_);

	gameModel_ -> subscribe (gamePanelView_);
	gameModel_ -> subscribe ( tableView_ );
	gameModel_ -> subscribe ( playersBox_ );
	gameModel_ -> subscribe ( handView_ );
	gameModel_ -> subscribe ( this );

	container_.add ( *gamePanelView_ );	
	container_.add ( *tableView_ );
	container_.add ( *playersBox_ );
	container_.add ( *handView_ );

	add (container_);

	container_.show ();
	gamePanelView_->show();
	tableView_->show();
	playersBox_->show();
	handView_->show();

}

GameWindow::~GameWindow () {
	delete gameModel_;
	delete gameController_;
	delete tableView_;
	delete gamePanelView_;
	delete handView_;
	delete playersBox_;
}

void GameWindow::update () {
	std::vector<Player*> players = gameModel_ -> winningPlayers();
	if ( players.size() !=0 ){
		std::cout << "GAME OVER" << std::endl;
		std::ostringstream os;
		os << "Congratulations Player " << players[0]->id()+1;
		for ( int i=1; i<players.size(); i++ ){
			os << " and " << players[i]->id()+1;
		}
		os << " You are victorious!";
		DialogBox dialogBox( *this, "Game Over", os.str() ); 
	}
}


// Show dialog box when needed
void GameWindow::showDialogBox (){
	std::string output = "Discards for:\n";
	for (int i=0; i<4; i++) {
		std::stringstream ss;
		ss << i+1;
		output = output + "\t Player " + ss.str() + ": " + gameModel_ -> discardedCardForPlayer(i) + "\n";
	}

	DialogBox dialogBox( *this, "Round over", output ); 
}