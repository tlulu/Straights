#ifndef GAMEPANELVIEW_H
#define GAMEPANELVIEW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/textview.h>

#include "GameModel.h"
#include "GameController.h"

class GamePanelView : public Gtk::HBox {
public:
  GamePanelView ( GameModel*, GameController* );
  virtual ~GamePanelView ();

protected:
  void onStartButtonClick ();
  void onEndButtonClick ();

private:  
  GameModel *model_;
  GameController *controller_;

  Gtk::Button startButton_;
  Gtk::TextView seed_;
  Gtk::Button endButton_;
};

#endif