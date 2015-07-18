#include "PlayerView.h"
#include <sstream>

PlayerView::PlayerView () : totalPlayers_(4) {
  for ( int i = 0; i < totalPlayers_; i++ ) {
    std::ostringstream os;
    os << "Player " << (i+1) ;

    players_[i] = new Gtk::Frame ();
    players_[i] -> set_label( os.str() );
    //labels_[i] = new Gtk::Label ();
    //players_[i] -> add( *labels_[i] );
    add ( *players_[i] );

    //buttons_[i] = new Gtk::Button ();
    //add (*buttons_[i]);
    //buttons_[i]->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &HandView::onPlayerButtonClick),i));

  }
}

PlayerView::~PlayerView () {
  for ( int i = 0; i < totalPlayers_; i++ ) {
    delete buttons_[i];
    delete players_[i];
    //delete labels_[i];
  }
}

void PlayerView::update () {
  for ( int i = 0; i < totalPlayers_; i++ ) {
    // update score
    // update discarded cards
  }
}

void PlayerView::onPlayerButtonClick ( int index ) {
  //controller_ -> changeComputerToHuman (index);
}

