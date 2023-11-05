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
	if (isprint(str.at(0)) && str.length() == 1)
		return true;
	else if (isdigit(str.at(0)))
	{
		if (str.compare(ss.str()) <= 0 && str.compare(ss2.str()) <= 0)
			if (isprint(std::stoi(str.c_str())))
				return true;
		return false;
	}
	else
		return false;
}

static bool isInt(std::string str)
{
	for (int i = (str.at(0) == '-'); i < static_cast<int>(str.length()); ++i)
		if (!isdigit(str.at(i)))
			return false;
	if ((str.compare(ss.str()) >= 0 && ss.str().length() >= 10 && ss.str().at(0) != '-') || (str.compare(ss.str()) >= 0 && ss2.str().length() >= 11 && ss2.str().at(0) == '-'))
		return false;
	return true;
}

static bool isFloat(std::string str)
{
	std::stringstream ss;
	std::stringstream ss2;
	ss << 1.7976931348623157e38;
	ss2 << 1.7976931348623157e-38;
	if (str.compare(ss.str()) >= 0 || str.compare(ss2.str()) >= 0)
		return false;
	return true;
}

static bool isDouble(std::string str)
{
	std::stringstream ss;
	std::stringstream ss2;
	ss << 1.7976931348623157e308;
	ss2 << 1.7976931348623157e-308;
	if (str.compare(ss.str()) >= 0 || str.compare(ss2.str()) >= 0)
		return false;
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

void ScalarConverter::convert(std::string str) {
	char myChar;
	int myInt;
	float myFloat;
	double myDouble;

	switch (whatType(str)) {
		case 1:
			if (isdigit(str.at(0)))
				myChar = static_cast<char>(std::stoi(str.c_str()));
			else
				myChar = str.at(0);
			std::cout << "char: " << myChar << std::endl;
			std::cout << "int: " << static_cast<int>(myChar) << std::endl;
			std::cout << "float: " << static_cast<float>(myChar) << std::endl;
			std::cout << "double: " << static_cast<double>(myChar) << std::endl;
			break;
		case 2:
			myInt = std::stoi(str.c_str());
			if (isprint(myInt))
				std::cout << "char: " << static_cast<char>(myInt) << std::endl;
			else
				std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << myInt << std::endl;
			std::cout << "float: " << static_cast<float>(myInt) << std::endl;
			std::cout << "double: " << static_cast<double>(myInt) << std::endl;
			break;
		case 3:
			myFloat = std::stof(str.c_str());
			std::cout << "char: " << static_cast<char>(myFloat) << std::endl;
			std::cout << "int: " << static_cast<int>(myFloat) << std::endl;
			std::cout << "float: " << myFloat << std::endl;
			std::cout << "double: " << static_cast<double>(myFloat) << std::endl;
			break;
		case 4:
			myDouble = std::stod(str.c_str());
			std::cout << "char: " << static_cast<int>(myDouble) << std::endl;
			std::cout << "int: " << static_cast<int>(myDouble) << std::endl;
			std::cout << "float: " << static_cast<float>(myDouble) << std::endl;
			std::cout << "double: " << myDouble << std::endl;
		default:
			break;
	}
}
