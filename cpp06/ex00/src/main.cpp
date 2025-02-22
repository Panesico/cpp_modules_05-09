#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Invalid number of arguments!" << std::endl, 1);
	std::string str = argv[1];
	ScalarConverter::convert(str);
}
