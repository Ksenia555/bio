#pragma once
#include "Cell.h"

class TProkaryotes : public TCell
{
protected:
	int mesosomes;
public:
	TProkaryotes();
	TProkaryotes(int mesosomes_);
	virtual ~TProkaryotes();

	virtual int GetMesosomes();

	virtual void SetMesosomes(int mesosomes_);

	friend std::ostream& operator <<(std::ostream& o, TProkaryotes& cell);
	friend std::istream& operator >>(std::istream& i, TProkaryotes& cell);
};