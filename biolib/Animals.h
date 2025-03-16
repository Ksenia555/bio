#pragma once
#include "Eukaryotes.h"

class TAnimals : public TEukaryotes
{
protected:
	int mitochondria;
public:
	TAnimals();
	TAnimals(int mitochondria_);
	virtual ~TAnimals();

	virtual int GetMitochondria();
	virtual std::string GetLivingEnvironment();

	virtual void SetMitochondria(int mitochondria_);

	friend std::ostream& operator <<(std::ostream& o, TAnimals& cell);
	friend std::istream& operator >>(std::istream& i, TAnimals& cell);
};