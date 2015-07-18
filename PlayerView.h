#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>

#include "Observer.h"
//#include "GameModel.h"
//#include "GameController.h"

class PlayerView : public Gtk::HBox, public Observer {
public:
  //PlayerView ( GameModel*, GameController* );
  PlayerView ();
  virtual ~PlayerView ();

  void update ();

protected:
  void onPlayerButtonClick ( int );

private:
  const int totalPlayers_;  
  //GameModel *model_;
  //GameController *controller_;
  Gtk::Frame *players_[4];
  Gtk::Label *labels_[4];
  Gtk::Button *buttons_[4];

};

#endif