#include "../include/BitcoinExchange.hpp"


int main(int argc, char **argv) {
	if (argc != 2)
		return -1;
	std::ifstream file;
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Couldn't open file." << std::endl;
		return (-1);
	}
	std::string line;
	getline(file, line);
	if (line != "date,exchange_rate")
	{
		std::cout << "File format isn't correct." << std::endl;
		return (-1);
	}
	BitcoinExchange myBit;
	while (getline(file, line))
	{
		myBit.getExchange(line);
	}
	std::string myInput;
	std::cout << "Search for a date: ";
	getline(std::cin, myInput);
	myBit.getDate(myInput);
}
