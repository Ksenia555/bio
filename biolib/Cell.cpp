#include "Cell.h"
#include <stdexcept>
#include <string>

TCell::TCell()
{
	atf = 1;
	chromosome = 8;
}

TCell::TCell(double atf_, int chromosome_) : TCell::TCell()
{
	if (atf_ <= 0) atf_ = 1;
	else this->atf = atf_;

	if (chromosome_ < 8) chromosome_ = 8;
	else this->chromosome = chromosome_;
}


TCell::~TCell()
{
}

double TCell::GetATF()
{
	return atf;
}

int TCell::GetChromosome()
{
	return chromosome;
}

void TCell::SetATF(double atf_)
{
	if (atf_ <= 0)
		throw std::invalid_argument("Error ATF!!!Value must be non-negative");
	atf = atf_;
}

void TCell::SetChromosome(int chromosome_)
{
	if (chromosome_ < 8 || chromosome_ > 1300)
	{
		throw std::invalid_argument("Error Chromsome!!!Value must be non-negative");
	}
	else
	{
		chromosome = chromosome_;
	}
}


std::ostream& operator <<(std::ostream& o, TCell& cell)
{
	o << "Cell energy: " << cell.GetATF() << "\n" << "Num of chromosomes: " << cell.GetChromosome()<< "\n";

	return o;
}

std::istream& operator >>(std::istream& i, TCell& cell)
{
	double atf;
	int chromosome;

	std::cout << "Enter the count of ATF in the cell: ";
	i >> atf;
	std::cout << "Enter the count of chromosome in the cell: ";
	i >> chromosome;

	try {
		cell.SetATF(atf);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		cell.SetChromosome(chromosome);
	}
	catch (const std::invalid_argument& d) {
		std::cerr << "Error: " << d.what() << std::endl;
	}

	return i;
}
