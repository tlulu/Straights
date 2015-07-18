#include "GamePanelView.h"

GamePanelView::GamePanelView () {

  startButton_.set_label( "start" );
  endButton_.set_label( "end" );

  startButton_.signal_clicked().connect( sigc::mem_fun( *this, &GamePanelView::onStartButtonClick ) );
  endButton_.signal_clicked().connect( sigc::mem_fun( *this, &GamePanelView::onEndButtonClick ) );

  add (startButton_);
  add (seed_);
  add (endButton_);
}

GamePanelView::~GamePanelView () {}

void GamePanelView::onStartButtonClick () {
  // controller_ -> startGame();
}

void GamePanelView::onEndButtonClick () {
  // controller_ -> endGame();
}
