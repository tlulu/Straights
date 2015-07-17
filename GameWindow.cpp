#include <gtkmm/stock.h>
#include <iostream>

#include "GameWindow.h"
#include "Card.h"

GameWindow::GameWindow () : button ("Click me") {

	tableModel_ = new CardTableModel ();
	tableController_ = new CardTableController ( tableModel_ );
	tableView_ = new CardTableView ( tableModel_, tableController_ );

	tableModel_ -> subscribe ( tableView_ );

	handModel_ = new HandModel ();
	handController_ = new HandController ( handModel_ );
	handView_ = new HandView ( handModel_, handController_ );

	handModel_ -> subscribe ( handView_ );

	set_default_size (480, 360);
	add (vBox);
	
	button.signal_clicked().connect( sigc::mem_fun( *this, &GameWindow::onButtonClicked ) );

	vBox.add ( *tableView_ );
	vBox.add ( button );
	vBox.add ( *handView_ );
	
	show_all ();
}

GameWindow::~GameWindow () {
	delete tableModel_;
	delete tableController_;
	delete tableView_;
}

void GameWindow::onButtonClicked () {
	Card c (Suit(rand() % 4), Rank(rand() % 13) );
	tableController_ -> showCard ( c );
	handController_ -> addCardToHand ( c );
	//handController_ -> removeCardFromHand (c);
}