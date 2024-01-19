#include "../include/RPN.hpp"

bool RPN::isValidRPN(const std::string& expression) {
	std::stack<double> operandStack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            operandStack.push(std::stod(token));
        } else {
            if (operandStack.size() < 2) {
                return false;
            }

            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();

            if (token == "+") {
                operandStack.push(operand1 + operand2);
            } else if (token == "-") {
                operandStack.push(operand1 - operand2);
            } else if (token == "*") {
                operandStack.push(operand1 * operand2);
            } else if (token == "/") {
                if (operand2 == 0) {
                    return false;
                }
                operandStack.push(operand1 / operand2);
            } else {
                return false;
            }
        }
    }

    return operandStack.size() == 1;
}

double RPN::calculateRPN(const std::string& expression) {
    std::istringstream iss(expression);

    std::string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1]))) {
            // If the token is a number, push it onto the stack
            _operandStack.push(atof(token.c_str()));
        } else {
            // If the token is an operator, pop operands from the stack, perform the operation, and push the result back
            double operand2 = _operandStack.top();
            _operandStack.pop();
            double operand1 = _operandStack.top();
            _operandStack.pop();

            if (token == "+") {
                _operandStack.push(operand1 + operand2);
            } else if (token == "-") {
                _operandStack.push(operand1 - operand2);
            } else if (token == "*") {
                _operandStack.push(operand1 * operand2);
            } else if (token == "/") {
                if (operand2 != 0) {
                    _operandStack.push(operand1 / operand2);
                } else {
                    std::cerr << "Error: Division by zero." << std::endl;
                    exit(1);
                }
            } else {
                std::cerr << "Error: Unknown operator '" << token << "'" << std::endl;
                exit(1);
            }
        }
    }

    if (_operandStack.size() == 1) {
        // If there's only one value left on the stack, it's the final result
        return _operandStack.top();
    } else {
        std::cerr << "Error: Invalid RPN expression." << std::endl;
        exit(1);
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
