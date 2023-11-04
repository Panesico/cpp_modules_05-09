#pragma once
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <limits>

#define ISCHAR 1
#define ISINT 2
#define ISFLOAT 3
#define ISDOUBLE 4

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const std::string input);
public:
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);

	static void convert(std::string str);

	class ErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};