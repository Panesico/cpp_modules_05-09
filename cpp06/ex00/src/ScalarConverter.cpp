#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <sstream>

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
	if (!isprint(str.at(0)))
		return false;
	else
		return true;
}

static bool isInt(std::string str)
{
	for (int i = (str.at(0) == '-'); i < static_cast<int>(str.length()); ++i)
		if (!isdigit(str.at(i)))
			return false;
	return true;
}

static bool isFloat(std::string str)
{
	std::stringstream ss;
	std::stringstream ss2;
	ss << 1.7976931348623157e38;
	ss2 << 1.7976931348623157e-38;
	if (str.compare(ss.str()) >= 0 && str.compare(ss.str()) >= 0)
		return false;
	return true;
}

static bool isDouble(std::string str)
{
	std::stringstream ss;
	std::stringstream ss2;
	ss << 1.7976931348623157e308;
	ss2 << 1.7976931348623157e-308;
	if (str.compare(ss.str()) >= 0 && str.compare(ss.str()) >= 0)
		return false;
	return true;
}

static int whatType(std::string str)
{
	if (isChar(str))
		return ISCHAR;
	if (isInt(str))
		return ISINT;
	if (isFloat(str))
		return ISFLOAT;
	if (isDouble(str))
		return ISDOUBLE;
	return -1;
}

void ScalarConverter::convert(std::string str) {
	switch (whatType(str)) {
		case ISCHAR:
			char myChar = str.at(0);
			std::cout << "char: " << myChar << std::endl;
			std::cout << "int: " << static_cast<int>(myChar) << std::endl;
			std::cout << "float: " << static_cast<float>(myChar) << std::endl;
			std::cout << "double: " << static_cast<double>(myChar) << std::endl;
			break;
		case ISINT:
			int myInt = std::stoi(str);
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << myInt << std::endl;
			std::cout << "float: " << static_cast<float>(myInt) << std::endl;
			std::cout << "double: " << static_cast<double>(myInt) << std::endl;
			break;
		case ISFLOAT:
			float myFloat = std::stof(str);
			std::cout << "char: " << static_cast<char>(myFloat) << std::endl;
			std::cout << "int: " << static_cast<int>(myFloat) << std::endl;
			std::cout << "float: " << myFloat << std::endl;
			std::cout << "double: " << static_cast<double>(myFloat) << std::endl;
			break;
		case ISDOUBLE:
			double myDouble = std::stod(str);
			std::cout << "char: " << static_cast<int>(myDouble) << std::endl;
			std::cout << "int: " << static_cast<int>(myDouble) << std::endl;
			std::cout << "float: " << static_cast<float>(myDouble) << std::endl;
			std::cout << "double: " << myDouble << std::endl;
	}
}