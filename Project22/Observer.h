#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
	virtual void update () = 0;
  virtual void showDialogBox (){}
};

#endif