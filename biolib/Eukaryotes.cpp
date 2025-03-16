#include "Eukaryotes.h"

TEukaryotes::TEukaryotes()
{
	core = 1;
}

TEukaryotes::TEukaryotes(int core_)
{
	if (core_ <= 0) core_ = 1;
	else this->core = core_;
}

TEukaryotes::~TEukaryotes()
{
}

int TEukaryotes::GetCore()
{
	return core;
}

void TEukaryotes::SetCore(int core_)
{
	if (core_ <= 0)
		throw std::invalid_argument("Error Core!!!Value must be non-negative");
	core = core_;
}

std::ostream& operator <<(std::ostream& o, TEukaryotes& cell)
{
	o << "Cell energy: " << cell.GetATF() << "\n" << "Num of chromosomes: " << cell.GetChromosome() << "\n";

	o << "Cores of eukaryotes: " << cell.GetCore() << "\n";

	return o;
}

std::istream& operator >>(std::istream& i, TEukaryotes& cell)
{
	double atf;
	int chromosome;
	int core;

	std::cout << "Enter the count of ATF in the cell: ";
	i >> atf;
	std::cout << "Enter the count of chromosome in the cell: ";
	i >> chromosome;
	std::cout << "Enter the count of core in the eukaryotes cell: ";
	i >> core;

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

	try {
		cell.SetCore(core);
	}
	catch (const std::invalid_argument& d) {
		std::cerr << "Error: " << d.what() << std::endl;
	}

	return i;
}