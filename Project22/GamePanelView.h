#ifndef GAMEPANELVIEW_H
#define GAMEPANELVIEW_H

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
  void onStartButtonClick ();
  void onEndButtonClick ();
  void onNewGameButtonClick ();

private:  
  GameModel *model_;
  GameController *controller_;

  Gtk::Button startButton_;
  Gtk::Button newGameButton_;
  Gtk::Entry seed_;
  Gtk::Button endButton_;
};

#endif