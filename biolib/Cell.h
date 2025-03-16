#pragma once
#include <iostream>
#include <string>

class TCell
{
protected:
	double atf;
	int chromosome;
public:
	TCell();
	TCell(double atf_, int chromosome_);
	~TCell();

	virtual double GetATF();
	virtual int GetChromosome();
	virtual std::string GetLivingEnvironment() = 0;

	virtual void SetATF(double atf_);	
	virtual void SetChromosome(int chromosome_);

	friend std::ostream& operator <<(std::ostream& o, TCell& cell);
	friend std::istream& operator >>(std::istream& i, TCell& cell);
};


