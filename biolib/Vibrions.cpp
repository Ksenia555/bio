#include "Vibrions.h"


TVibrions::TVibrions()
{
	length = 1.5;
}

TVibrions::TVibrions(double length_)
{
	if (length_ <= 0) length_ = 10;
	else this->length = length_;
}

TVibrions::~TVibrions()
{
}

double TVibrions::GetLength()
{
	return length;
}

void TVibrions::SetLength(double length_)
{
	if (length_ <= 0)
		throw std::invalid_argument("Error Length!!!Value must be non-negative");
	length = length_;
}

std::string TVibrions::GetLivingEnvironment()
{
	return "fresh and sea water, soil, intestines";
}

std::ostream& operator <<(std::ostream& o, TVibrions& cell)
{
	o << "Cell energy: " << cell.GetATF() << "\n" << "Num of chromosomes: " << cell.GetChromosome() << "\n" << std::endl;

	o << "Mesosomes of prokaryotes: " << cell.GetMesosomes() << "\n" << "Length of vibrions: " << cell.GetLength() << std::endl;
	
	o << "Living Environment: " << cell.GetLivingEnvironment() << std::endl;

	return o;
}

std::istream& operator >>(std::istream& i, TVibrions& cell)
{
	double atf;
	int chromosome;
	int mesosomes;
	double length;

	std::cout << "Enter the count of ATF in the cell: ";
	i >> atf;
	std::cout << "Enter the count of chromosome in the cell: ";
	i >> chromosome;
	std::cout << "Enter the count of mesosomes in the prokaryotes cell: ";
	i >> mesosomes;
	std::cout << "Enter the count of length in the prokaryotes cell: ";
	i >> length;


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
		cell.SetLength(length);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return i;
}