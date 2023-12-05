#include "../include/RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
		return 1;
	}

	RPN myRPN;
	std::string rpnExpression = argv[1];
	long result = myRPN.evaluateRPN(rpnExpression);

	std::cout << "Result: " << result << std::endl;

	return 0;
}
