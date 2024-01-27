#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <stack>

class RPN {
private:
	std::stack<long> _operandStack;
public:
	RPN();

	RPN(RPN &copy);

	RPN &operator=(RPN &copy);

	~RPN();

	double calculateRPN(const std::string& expression);
	bool isValidRPN(const std::string& expression);
};
