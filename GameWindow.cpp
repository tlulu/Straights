#include <gtkmm/stock.h>
#include <iostream>

#include "GameWindow.h"
#include "Card.h"

GameWindow::GameWindow () : button ("Click me") {

	tableModel_ = new CardTableModel ();
	tableController_ = new CardTableController ( tableModel_ );
	tableView_ = new CardTableView ( tableModel_, tableController_ );

	tableModel_ -> subscribe ( tableView_ );

	set_default_size (480, 360);
	add (vBox);
	
	button.signal_clicked().connect( sigc::mem_fun( *this, &GameWindow::onButtonClicked ) );

	vBox.add ( *tableView_ );
	vBox.add ( button );
	
	show_all ();
}

GameWindow::~GameWindow () {
	delete tableModel_;
	delete tableController_;
	delete tableView_;
}

void GameWindow::onButtonClicked () {
	//std::cout << rand() * 4 << std::endl;
	tableController_ -> showCard ( Card ( Suit(rand() % 4), Rank(rand() % 13) ) );
}