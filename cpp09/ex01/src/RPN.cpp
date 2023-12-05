#include "../include/RPN.hpp"

bool RPN::isOperator(char token) {
	return token == '+' || token == '-' || token == '*' || token == '/';
}

bool RPN::isOperand(const std::string& token) {
	try {
		std::stod(token);
		return true;
	} catch (const std::invalid_argument&) {
		return false;
	} catch (const std::out_of_range&) {
		return false;
	}
}

bool RPN::isValidToken(const std::string& token) {
	if (isOperator(token.at(0))) {
		return token.size() == 1;
	}

	size_t pos;
	std::stod(token, &pos);

	return pos == token.size();
}

long RPN::performOperation(long operand1, long operand2, const std::string& op) {
	if (op == "+") return operand1 + operand2;
	if (op == "-") return operand1 - operand2;
	if (op == "*") return operand1 * operand2;
	if (op == "/") return operand1 / operand2;
	return 0;
}

long RPN::evaluateRPN(const std::string& rpnExpression) {
	std::stringstream ss(rpnExpression);
	std::string token;

	while (ss >> token) {
		if (isValidToken(token)) {
			if (isOperand(token)) {
				_operandStack.push(std::stod(token));
			} else if (isOperator(token.at(0))) {
				if (_operandStack.size() < 2) {
					std::cout << "Error: Insufficient operands for operator " << token << std::endl;
					return 0;
				}

				double operand2 = _operandStack.top();
				_operandStack.pop();

				double operand1 = _operandStack.top();
				_operandStack.pop();

				double result = performOperation(operand1, operand2, token);
				_operandStack.push(result);
			}
		} else {
			std::cout << "Error: Invalid token in RPN expression: " << token << std::endl;
			return 0;
		}
	}

	if (_operandStack.size() == 1) {
		return _operandStack.top();
	} else {
		std::cout << "Error: Too many operands in RPN expression" << std::endl;
		return 0;
	}
}

RPN::RPN()
{
	std::cout << "Calling RPN constructor" << std::endl;
}

RPN::RPN(RPN &copy)
{
	std::cout << "Calling RPN copy constructor" << std::endl;
	if (this != &copy)
		_operandStack = copy._operandStack;
}

RPN &RPN::operator=(RPN &copy)
{
	std::cout << "Calling RPN equal operator" << std::endl;
	if (this != &copy)
	{
		_operandStack = copy._operandStack;
		return *this;
	}
	return *this;
}

RPN::~RPN()
{
	std::cout << "Calling RPN destructor" << std::endl;
}
