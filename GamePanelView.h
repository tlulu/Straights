#ifndef GAMEPANELVIEW_H
#define GAMEPANELVIEW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/textview.h>

class GamePanelView : public Gtk::HBox {
public:
  GamePanelView ();
  virtual ~GamePanelView ();

protected:
  void onStartButtonClick ();
  void onEndButtonClick ();

private:  
  //GameModel *model_;
  //GameController *controller_;

  Gtk::Button startButton_;
  Gtk::TextView seed_;
  Gtk::Button endButton_;
};

#endif