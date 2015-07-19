#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <gtkmm/dialog.h>
#include <gtkmm/box.h>
#include <string>
#include <vector>


class DialogBox: Gtk::Dialog {
public:
  DialogBox ( Gtk::Window & parentWindow, std::string title, std::string message );
  virtual ~DialogBox();
private:
  std::string message_;
};

#endif