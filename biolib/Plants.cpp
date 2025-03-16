#include "Plants.h"

TPlants::TPlants()
{
	plastids = 1;
}

TPlants::TPlants(int plastids_)
{
	if (plastids_ <= 0) plastids_ = 1;
	else this->plastids = plastids_;
}

TPlants::~TPlants()
{
}

int TPlants::GetPlastids()
{
	return plastids;
}

void TPlants::SetPlastids(int plastids_)
{
	if (plastids_ <= 0)
		throw std::invalid_argument("Error Plastids!!!Value must be non-negative");
	plastids = plastids_;
}

std::string TPlants::GetLivingEnvironment()
{
	return "air, water";
}

std::ostream& operator <<(std::ostream& o, TPlants& cell)
{
	o << "Cell energy: " << cell.GetATF() << "\n" << "Num of chromosomes: " << cell.GetChromosome() << "\n" << std::endl;

	o << "Cores of eukaryotes: " << cell.GetCore() << "\n" << "Plastids of eukaryotes: " << cell.GetPlastids() << std::endl;

	o << "Living Environment: " << cell.GetLivingEnvironment() << std::endl;

	return o;
}

std::istream& operator >>(std::istream& i, TPlants& cell)
{
	double atf;
	int chromosome;
	int core;
	int plastids;

	std::cout << "Enter the count of ATF in the cell: ";
	i >> atf;
	std::cout << "Enter the count of chromosome in the cell: ";
	i >> chromosome;
	std::cout << "Enter the count of core in the eukaryotes cell: ";
	i >> core;
	std::cout << "Enter the count of plastids in the eukaryotes cell: ";
	i >> plastids;

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

	try {
		cell.SetPlastids(plastids);
	}
	catch (const std::invalid_argument& d) {
		std::cerr << "Error: " << d.what() << std::endl;
	}
	
	return i;
}