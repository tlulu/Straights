#include "PlayerView.h"
#include <sstream>

PlayerView::PlayerView ( GameModel *model, GameController *controller, int id ) : 
                            model_ (model), 
                            controller_ (controller),
                            playerId_ (id) {
  
  std::stringstream ss;
  ss << playerId_+1;
  set_label ("Player " + ss.str());
  set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
  set_shadow_type( Gtk::SHADOW_ETCHED_OUT );

  add (vBox_);

  pLabel_.set_text ("0");
  pointsLabel_.set_text ("points");
  pointsBox_.add (pLabel_);
  pointsBox_.add (pointsLabel_);

  dLabel_.set_text ("0");
  discardsLabel_.set_text ("discards");
  discardsBox_.add (dLabel_);
  discardsBox_.add (discardsLabel_);

  joinButton_.set_label ("Join Game");
  joinButton_.signal_clicked().connect( sigc::mem_fun( *this, &PlayerView::onJoinButtonClick ) );

  vBox_.add (pointsBox_);
  vBox_.add (discardsBox_);
  vBox_.add (joinButton_);

  show_all();

}

PlayerView::~PlayerView () {
  
}

void PlayerView::update () {
  if (model_ -> isGameInProgress() || model_ -> playerIsComputer (playerId_)) {
    joinButton_.hide();
  }else{
    joinButton_.show();
  }

  int points = model_ -> scoreForPlayer (playerId_);
  Hand *discardedHand = model_ -> discardedHandForPlayer (playerId_);
  int discardedPoints = discardedHand->size();

  std::stringstream ss;
  ss << points;
  pLabel_.set_text (ss.str());
  ss.str("");
  ss << discardedPoints;
  dLabel_.set_text (ss.str());

  if (model_ -> currentPlayer() == playerId_ && model_ -> isGameInProgress() ) {
    set_shadow_type( Gtk::SHADOW_IN );
  } else {
    set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
  }
}

void PlayerView::onJoinButtonClick () {
  controller_ -> joinGame (playerId_);
}

