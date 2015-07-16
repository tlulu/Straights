#ifndef SUBJECT_H
#define SUBJECT_H

#include <set>
#include "Observer.h"

class Subject {
public:
	void subscribe ( Observer* );
	void unsubscribe ( Observer* );

protected:
	void notify ();

private:
	std::set<Observer*> observers_;
};

#endif