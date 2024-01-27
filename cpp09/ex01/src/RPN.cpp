#include "../include/RPN.hpp"

static int stod(const std::string& str) {
    std::istringstream ss(str);
    double result;

    // Check for conversion success
    if (!(ss >> result) || !ss.eof()) {
        throw std::invalid_argument("Invalid number: " + str);
    }

    return result;
}

static bool isValidDigit(const std::string& str) {
    bool hasdot = false;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it)) {
            if (it == str.begin() && (*it == '-' || *it == '+'))
            {
                if (str.size() == 1)
                    return false;
                continue;
            }
            if (it != str.begin() && *it == '.')
            {
                if (!hasdot)
                {
                    hasdot = true;
                    continue;
                }
                else
                    return false;
            }
            return false;
        }
    }
    return true;
}

static bool isValidToken(const std::string& str) {
    return (str == "+" || str == "-" || str == "*" || str == "/");
}

double RPN::calculateRPN(const std::string& str) {
        std::stack<int> stk;
        std::istringstream stream(str);
        std::string token;
        double result = 0;
        bool firstIter = false;

        while (!stream.eof()) {
            stream >> token;

            if (!isValidToken(token)) {
                if (!isValidDigit(token)) {
                    throw std::invalid_argument("Invalid RPN expression");
                }
                stk.push(stod(token));
                continue;
            }

            if (stk.size() < 2 && !firstIter) {
                throw std::invalid_argument("Invalid RPN expression");
            }

            if (stk.size() == 0 && firstIter) {
                throw std::invalid_argument("Invalid RPN expression");
            }
        
            while (stk.size() > 0) {
                double num2 = stk.top();
                stk.pop();
                if (!firstIter)
                {
                    result = stk.top();
                    stk.pop();
                    firstIter = true;
                }
                
                if (token == "+") {
                    result = num2 + result;
                } else if (token == "-") {
                    result = num2 - result;
                } else if (token == "*") {
                    result = num2 * result;
                } else {
                    if (num2 == 0)
                        throw std::invalid_argument("Invalid RPN expression");
                    result = num2 / result;
                }
            }
        }
        if (stk.size() > 0)
            throw std::invalid_argument("Invalid RPN expression");
        return result;
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
