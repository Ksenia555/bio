#pragma once

#include "Prokaryotes.h"


class TStaphylococcus : public TProkaryotes
{
protected:
	int cellCoccus;
public:
	TStaphylococcus();
	TStaphylococcus(int cellCoccus_);
	virtual ~TStaphylococcus();

	virtual int GetCellCoccus();
	virtual std::string GetLivingEnvironment();

	virtual void SetCellCoccus(int cellCoccus_);

	friend std::ostream& operator <<(std::ostream& o, TStaphylococcus& cell);
	friend std::istream& operator >>(std::istream& i, TStaphylococcus& cell);
};