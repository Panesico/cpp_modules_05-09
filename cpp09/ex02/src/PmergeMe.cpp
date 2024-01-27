#include "../include/PmergeMe.hpp"

void PmergeMe::binaryInsert(std::vector<double>& sortedSeq, double element) {
    // Binary search to find the correct position to insert the element
    std::vector<double>::iterator it = std::lower_bound(sortedSeq.begin(), sortedSeq.end(), element);

    // Insert the element at the found position
    sortedSeq.insert(it, element);
}

void PmergeMe::specialInsert(std::vector<double>& sortedSeq, const std::vector<double>& remainingElements) {
    // Insert the element that was paired with the first and smallest element of sortedSeq
    sortedSeq.insert(sortedSeq.begin(), remainingElements[0]);

    // Insert the remaining elements using binary search for each insertion
    for (size_t i = 1; i < remainingElements.size(); ++i) {
        binaryInsert(sortedSeq, remainingElements[i]);
    }
}

std::list<double> PmergeMe::merge(std::vector<double>& X) {
    size_t n = X.size();

    if (n <= 1) {
        // Base case: already sorted
        return std::list<double>(X.begin(), X.end());
    }

    // Step 1: Pair elements and determine larger element in each pair
	std::vector<double> largerElements;
    for (size_t i = 0; i < n - 1; i += 2) {
        double larger = std::max(X[i], X[i + 1]);
        largerElements.push_back(larger);
    }

    // Step 2: Recursively sort the larger elements
    merge(largerElements);

    // Step 3: Insert at the start of S the element that was paired with the first and smallest element of S
    std::vector<double> sortedSeq;
    sortedSeq.push_back(X.front());

    // Step 4: Insert the remaining elements using specialInsert
    std::vector<double> remainingElements(X.begin() + 1, X.end());
    specialInsert(sortedSeq, remainingElements);

    // copy the vector sortedSeq back to an std::list

	return std::list<double>(sortedSeq.begin(), sortedSeq.end());
}