#include "../include/RPN.hpp"

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

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
		return 1;
	}
	
	std::string rpnExpression = argv[1];
	std::istringstream stream(rpnExpression);
	int num_counter = 0;
	while (!stream.eof()) {
		stream >> rpnExpression;
		if (isValidDigit(rpnExpression))
			num_counter++;
	}
	if (num_counter >= 10)
	{
		std::cout << "Too many numbers" << std::endl;
		return 1;
	}
	RPN myRPN;
	rpnExpression = argv[1];
	double result = 0;
	try {
		result = myRPN.calculateRPN(rpnExpression);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::cout << "Result: " << std::setprecision(15) << result << std::endl;

	return 0;
}
