#pragma once
#include "Eukaryotes.h"

class TPlants : public TEukaryotes
{
protected:
	int plastids;
public:
	TPlants();
	TPlants(int plastids_);
	virtual ~TPlants();

	virtual int GetPlastids();
	virtual std::string GetLivingEnvironment();

	virtual void SetPlastids(int plastids_);

	friend std::ostream& operator <<(std::ostream& o, TPlants& cell);
	friend std::istream& operator >>(std::istream& i, TPlants& cell);
};