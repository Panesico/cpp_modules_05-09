#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>

class PmergeMe
{
public:
	void specialInsert(std::vector<double>& sortedSeq, const std::vector<double>& remainingElements);
	void binaryInsert(std::vector<double>& sortedSeq, double element);
	std::list<double> merge(std::vector<double>& X);
};
