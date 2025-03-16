#pragma once
#include "Cell.h"

class TEukaryotes : public TCell
{
protected:
	int core;
public:
	TEukaryotes();
	TEukaryotes(int core_);
	virtual ~TEukaryotes();

	virtual int GetCore();

	virtual void SetCore(int core_);

	friend std::ostream& operator <<(std::ostream& o, TEukaryotes& cell);
	friend std::istream& operator >>(std::istream& i, TEukaryotes& cell);
};