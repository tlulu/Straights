#include <gtkmm/main.h>
#include <string>

#include "GamePanelView.h"

GamePanelView::GamePanelView (GameModel *model, GameController *controller) : 
                                  model_ (model), 
                                  controller_ (controller) {

  startButton_.set_label( "Start" );
  newGameButton_.set_label("New Game");
  endButton_.set_label( "End" );
  seed_.set_text ("0");

  startButton_.signal_clicked().connect( sigc::mem_fun( *this, &GamePanelView::onStartButtonClick ) );
  newGameButton_.signal_clicked().connect ( sigc::mem_fun( *this, &GamePanelView::onNewGameButtonClick ) );
  endButton_.signal_clicked().connect( sigc::mem_fun( *this, &GamePanelView::onEndButtonClick ) );

  add (startButton_);
  add (newGameButton_);
  add (seed_);
  add (endButton_);

  show_all();
  newGameButton_.hide ();
}

GamePanelView::~GamePanelView () {}

void GamePanelView::onStartButtonClick () {
  controller_ -> startGame();


}

void GamePanelView::onNewGameButtonClick () {
  std::string s = seed_.get_text();
  std::string::size_type sz; 
  int seed = 0;
  try{
    int seed = std::stoi(s, &(sz));
  }catch (std::invalid_argument&) {
    seed = 0;
  }
  controller_ -> newGame( seed );
}

void GamePanelView::onEndButtonClick () {
  Gtk::Main::quit();
}

void GamePanelView::update () {
  if ( model_ -> isGameInProgress () ) {
    newGameButton_.show();
    startButton_.hide();
  } else {
    newGameButton_.hide();
    startButton_.show();
  }
}