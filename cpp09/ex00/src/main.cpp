#include "../include/BitcoinExchange.hpp"


int main(int argc, char **argv) {
	if (argc != 2)
		return -1;
	std::ifstream file;
	file.open("data.csv");
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
	std::ifstream file2;
	file2.open(argv[1]);
	if (!file2.is_open())
	{
		std::cout << "Couldn't open file." << std::endl;
		return (-1);
	}
	std::string line2;
	getline(file2, line2);
	if (line2 != "date | value")
	{
		std::cout << "File format isn't correct." << std::endl;
		return (-1);
	}
	BitcoinExchange myBit;
	while (getline(file, line))
	{
		myBit.getDatabase(line);
	}
	while (getline(file2, line2))
	{
		myBit.getExchange(line2);
	}
	if (myBit.getDataMap().empty() || myBit.getExchangeMap().empty()){
		std::cerr << "No dates provided in database" << std::endl;
		std::exit(-1);
	}
	myBit.getDate();
}
