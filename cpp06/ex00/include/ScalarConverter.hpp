#pragma once
#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const std::string input);
public:
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);

	static void convert(std::string str);
};
