#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
private:
	std::stack<long> _operandStack;
public:
	RPN();

	RPN(RPN &copy);

	RPN &operator=(RPN &copy);

	~RPN();

	bool isOperator(char token);
	bool isOperand(const std::string& token);
	bool isValidToken(const std::string& token);
	long performOperation(long operand1, long operand2, const std::string& op);
	long evaluateRPN(const std::string& rpnExpression);
};
