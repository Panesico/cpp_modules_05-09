#include "../include/PmergeMe.hpp"

static double stod(const std::string str) {
    std::istringstream ss(str);
    double result;

    // Check for conversion success
    if (!(ss >> result) || !ss.eof()) {
        throw std::invalid_argument("Invalid number: " + str);
    }

    return result;
}

static bool isValidDigit(const std::string str) {
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

int main(int ac, char* av[])
{
	if (ac <= 1)
	{
		std::cout << "Error: No input sequence provided." << std::endl;
		return 1;
	}
	PmergeMe pmergeMe;
	std::list<double> inputSequence;
	if (ac > 2)
	{
		for (int i = 1; i < ac; ++i)
		{
			try
			{
				if (!isValidDigit(av[i]))
				{
					std::cout << "Error: Invalid input sequence provided." << std::endl;
					return 1;
				}
				inputSequence.push_back(stod(av[i]));
			}
			catch (std::invalid_argument& e)
			{
				std::cout << "Error: Invalid input sequence provided." << std::endl;
				return 1;
			}
		}
	}
	else
	{
		std::istringstream stream(av[1]);
		std::string token;
		while (!stream.eof())
		{
			stream >> token;
			try
			{
				if (!isValidDigit(token))
				{
					std::cout << "Error: Invalid input sequence provided." << std::endl;
					return 1;
				}
				inputSequence.push_back(stod(token));
			}
			catch (std::invalid_argument& e)
			{
				std::cout << "Error: Invalid input sequence provided." << std::endl;
				return 1;
			}
		}
	}

	// copy inputSequence to inputSequenceCopy vector

	std::cout << "Input sequence: ";

	std::vector<double> inputSequenceCopy;
	for (std::list<double>::iterator it = inputSequence.begin(); it != inputSequence.end(); ++it)
	{
		inputSequenceCopy.push_back(*it);
		std::cout << std::setprecision(15) << *it << " ";
	}

	std::cout << std::endl;

	inputSequence = pmergeMe.merge(inputSequenceCopy);

	std::cout << "Sorted sequence: ";

	for (std::list<double>::iterator it = inputSequence.begin(); it != inputSequence.end(); ++it)
		std::cout << std::setprecision(15) << *it << " ";

	std::cout << std::endl;

	return 0;
}
