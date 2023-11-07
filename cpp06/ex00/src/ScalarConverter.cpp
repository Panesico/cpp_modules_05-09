#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input)
{
	std::cout << "ScalarConverter Constructor for " << input << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Deconstructor called" << std::endl;
}

static bool isChar(std::string str)
{
	if (isprint(str.at(0)) && str.length() == 1 && !isdigit(str.at(0)))
		return true;
	else if (!isascii(isprint(static_cast<unsigned char>(str.at(0)))) && str.length() == 1 && !isdigit(str.at(0)))
		return true;
	else
		return false;
}

static bool isInt(std::string str)
{
	for (int i = (str.at(0) == '-'); i < static_cast<int>(str.length()); ++i)
		if (!isdigit(str.at(i)))
			return false;
	try {
		std::stoi(str);
	} catch (...) {return false;}
	return true;
}

static bool isFloat(std::string str)
{
	if (str.compare("-inf") && str.compare("inff") && str.compare("nanf"))
	{
		for (int i = (str.at(0) == '-'); i < static_cast<int>(str.length()); ++i)
			if (!isdigit(str.at(i)) && str.at(i) != '.')
				return false;
	}
	try {
		std::stof(str);
	} catch (...) {return false;}
	return true;
}

static bool isDouble(std::string str)
{
	if (str.compare("-inf") && str.compare("inf") && str.compare("nan"))
	{
		for (int i = (str.at(0) == '-'); i < static_cast<int>(str.length()); ++i)
			if (!isdigit(str.at(i)) && str.at(i) != '.')
				return false;
	}
	try {
		std::stod(str);
	} catch (...) {return false;}
	return true;
}

static int whatType(std::string str)
{
	if (str.empty())
		return -1;
	if (isChar(str))
		return 1;
	if (isInt(str))
		return 2;
	if (isFloat(str))
		return 3;
	if (isDouble(str))
		return 4;
	return -1;
}

int getPrecision(std::string str) {

	int counter = 0;
	int i;
	if (str.find(".") >= str.length())
		return 1;
	for (i = str.length() - 1; i != 0 && str.at(i) == '0'; --i);
	for (int j = i; j != 0 && str.at(j) != '.'; --j)
		++counter;
	if (counter)
		return counter;
	else
		return 1;
}

void ScalarConverter::convert(std::string str) {
	unsigned char myChar;
	int myInt;
	float myFloat;
	double myDouble;

	switch (whatType(str))
	{
		case 1:
			myChar = str.at(0);
			if (isprint(myChar))
				std::cout << "char: " << myChar << std::endl;
			else if (myChar < 255)
				std::cout << "char: " << "Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(myChar) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(getPrecision(std::to_string(myChar))) <<static_cast<float>(myChar) << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(getPrecision(std::to_string(myChar))) << static_cast<double>(myChar) << std::endl;
		break;
		case 2:
			myInt = std::stoi(str);
			if (isprint(static_cast<char>(myInt)))
				std::cout << "char: " << static_cast<char>(myInt) << std::endl;
			else if (myInt < 255 && myInt >= 0)
				std::cout << "char: " << "Non displayable" << std::endl;
			else
				std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << myInt << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(getPrecision(std::to_string(myInt))) << static_cast<float>(myInt) << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(getPrecision(std::to_string(myInt))) << static_cast<double>(myInt) << std::endl;
		break;
		case 3:
			myFloat = std::stof(str);
			if (isprint(static_cast<char>(myFloat)))
				std::cout << "char: " << static_cast<char>(myFloat) << std::endl;
			else if (myFloat < 255 && myFloat >= 0)
				std::cout << "char: " << "Non displayable" << std::endl;
			else
				std::cout << "char: " << "impossible" << std::endl;
			if (static_cast<int>(myFloat) == std::numeric_limits<int>::min())
				std::cout << "int: " << "impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(myFloat) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(getPrecision(std::to_string(myFloat))) << myFloat << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(getPrecision(std::to_string(myFloat))) << static_cast<double>(myFloat) << std::endl;
		break;
		case 4:
			myDouble = std::stod(str);
			if (isprint(static_cast<char>(myDouble)))
				std::cout << "char: " << static_cast<char>(myDouble) << std::endl;
			else if (myDouble < 255 && myDouble >= 0)
				std::cout << "char: " << "Non displayable" << std::endl;
			else
				std::cout << "char: " << "impossible" << std::endl;
			if (static_cast<int>(myDouble) == std::numeric_limits<int>::min())
				std::cout << "int: " << "impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(myDouble) << std::endl;
			if (myDouble > std::numeric_limits<float>::max() || myDouble < std::numeric_limits<float>::min())
				std::cout << "float: " << "impossible" << std::endl;
			else
				std::cout << "float: " << std::fixed << std::setprecision(getPrecision(std::to_string(myDouble))) << static_cast<float>(myDouble) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(getPrecision(std::to_string(myDouble))) << myDouble << std::endl;
			break;
		default:
			std::cout << "unkown type :(" << std::endl;
			break;
	}
}
