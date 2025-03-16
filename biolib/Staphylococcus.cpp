#include "Staphylococcus.h"

TStaphylococcus::TStaphylococcus()
{
	cellCoccus = 10;
}

TStaphylococcus::TStaphylococcus(int cellCoccus_)
{
	if (cellCoccus_ <= 0) cellCoccus_ = 10;
	else this->cellCoccus = cellCoccus_;
}

TStaphylococcus::~TStaphylococcus()
{
}

int TStaphylococcus::GetCellCoccus()
{
	return cellCoccus;
}

void TStaphylococcus::SetCellCoccus(int cellCoccus_)
{
	if (cellCoccus_ <= 0)
		throw std::invalid_argument("Error Cell Coccus!!!Value must be non-negative");
	cellCoccus = cellCoccus_;
}

std::string TStaphylococcus::GetLivingEnvironment()
{
	return "soil, air, milk, meat";
}

std::ostream& operator <<(std::ostream& o,TStaphylococcus& cell)
{
	o << "Cell energy: " << cell.GetATF() << "\n" << "Num of chromosomes: " << cell.GetChromosome() << "\n" << std::endl;

	o << "Mesosomes of prokaryotes: " << cell.GetMesosomes() << "\n" << "Cell of staphylococcus" << cell.GetCellCoccus() << std::endl;

	o << "Living Environment: " << cell.GetLivingEnvironment() << std::endl;

	return o;
}

std::istream& operator >>(std::istream& i, TStaphylococcus& cell)
{
	double atf;
	int chromosome;
	int mesosomes;
	int cellCoccus;

	std::cout << "Enter the count of ATF in the cell: ";
	i >> atf;
	std::cout << "Enter the count of chromosome in the cell: ";
	i >> chromosome;
	std::cout << "Enter the count of mesosomes in the prokaryotes cell: ";
	i >> mesosomes;
	std::cout << "Enter the count of cellCoccus in the prokaryotes cell: ";
	i >> cellCoccus;


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
		cell.SetMesosomes(mesosomes);
	}
	catch (const std::invalid_argument& d) {
		std::cerr << "Error: " << d.what() << std::endl;
	}



	try {
		cell.SetCellCoccus(cellCoccus);
	}
	catch (const std::invalid_argument& d) {
		std::cerr << "Error: " << d.what() << std::endl;
	}

	return i;
}