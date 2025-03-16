#include "Animals.h"


TAnimals::TAnimals()
{
	mitochondria = 1;
}

TAnimals::TAnimals(int mitochondria_)
{
	if (mitochondria_ <= 0) mitochondria_ = 1;
	else this->mitochondria = mitochondria_;
}

TAnimals::~TAnimals()
{
}

int TAnimals::GetMitochondria()
{
	return mitochondria;
}

void TAnimals::SetMitochondria(int mitochondria_)
{
	if (mitochondria_ <= 0)
		throw std::invalid_argument("Error mitochondria!!!Value must be non-negative");
	mitochondria = mitochondria_;
}

std::string TAnimals::GetLivingEnvironment()
{
	return "soil, air, water";
}

std::ostream& operator <<(std::ostream& o, TAnimals& cell)
{
	o << "Cell energy: " << cell.GetATF() << "\n" << "Num of chromosomes: " << cell.GetChromosome() << "\n" << std::endl;

	o << "Cores of eukaryotes: " << cell.GetCore() << "\n" << "Mitochondries of eukaryotes: " << cell.GetMitochondria() << std::endl;

	o << "Living Environment: " << cell.GetLivingEnvironment() << std::endl;

	return o;
}

std::istream& operator >>(std::istream& i, TAnimals& cell)
{
	double atf;
	int chromosome;
	int core;
	int mitochondria;

	std::cout << "Enter the count of ATF in the cell: ";
	i >> atf;
	std::cout << "Enter the count of chromosome in the cell: ";
	i >> chromosome;
	std::cout << "Enter the count of core in the eukaryotes cell: ";
	i >> core;
	std::cout << "Enter the count of mitochondria in the eukaryotes cell: ";
	i >> mitochondria;


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
		cell.SetMitochondria(mitochondria);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return i;
}