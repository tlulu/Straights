#ifndef HANDMODEL_H
#define HANDMODEL_H

class HandModel {
public:
	HandModel ();
	virtual ~HandModel ();

	void addCard ( const Card );
	std::vector<Card> hand () const;

private:
	std::vector<Card> hand_;
};

#endif