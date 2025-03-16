#include "Prokaryotes.h"

TProkaryotes::TProkaryotes()
{
	mesosomes = 10;
}

TProkaryotes::TProkaryotes(int mesosomes_)
{
	if (mesosomes_ <= 0) mesosomes_ = 10;
	else this->mesosomes = mesosomes_;
}

TProkaryotes::~TProkaryotes()
{
}

int TProkaryotes::GetMesosomes()
{
	return mesosomes;
}

void TProkaryotes::SetMesosomes(int mesosomes_)
{
	if (mesosomes_ <= 0)
		throw std::invalid_argument("Error Mesosomes!!!Value must be non-negative");
	mesosomes = mesosomes_;
}

std::ostream& operator <<(std::ostream& o, TProkaryotes& cell)
{
	o << "Cell energy: " << cell.GetATF() << "\n" << "Num of chromosomes: " << cell.GetChromosome() << "\n";

	o << "Mesosomes of prokaryotes: " << cell.GetMesosomes() << "\n";

	return o;
}

std::istream& operator >>(std::istream& i, TProkaryotes& cell)
{
	double atf;
	int chromosome;
	int mesosomes;

	std::cout << "Enter the count of ATF in the cell: ";
	i >> atf;
	std::cout << "Enter the count of chromosome in the cell: ";
	i >> chromosome;
	std::cout << "Enter the count of mesosomes in the prokaryotes cell: ";
	i >> mesosomes;

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
	
	return i;
}