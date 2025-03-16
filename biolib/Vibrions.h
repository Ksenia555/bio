#pragma once
#include "Prokaryotes.h"

class TVibrions : public TProkaryotes
{
protected:
	double length;
public:
	TVibrions();
	TVibrions(double lenght_);
	virtual ~TVibrions();

	virtual double GetLength();
	virtual std::string GetLivingEnvironment();

	virtual void SetLength(double lenght_);

	friend std::ostream& operator <<(std::ostream& o, TVibrions& cell);
	friend std::istream& operator >>(std::istream& i, TVibrions& cell);
};