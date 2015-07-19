#ifndef GAMEPANELVIEW_H
#define GAMEPANELVIEW_H

////////////////////////////////////////////////////////////

// View for starting a new game, and end game

////////////////////////////////////////////////////////////

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>

#include "GameModel.h"
#include "GameController.h"
#include "Observer.h"

class GamePanelView : public Gtk::HBox, public Observer {
public:
  GamePanelView ( GameModel*, GameController* );
  virtual ~GamePanelView ();

  void update ();

protected:
  void onStartButtonClick ();	// Action for start game
  void onEndButtonClick ();		// Action for end game
  void onNewGameButtonClick ();	// Action for new game

private:  
  GameModel *model_;
  GameController *controller_;

  Gtk::Button startButton_;
  Gtk::Button newGameButton_;
  Gtk::Entry seed_;
  Gtk::Button endButton_;
};

#endif