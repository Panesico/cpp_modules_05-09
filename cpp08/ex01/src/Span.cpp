#include "../include/Span.hpp"

void	Span::addNumber(int num)
{
	if (_myVector.size() < _size)
		_myVector.push_back(num);
}

unsigned int Span::shortestSpan()
{
	std::vector<int> sortedVector = _myVector;
	std::sort(sortedVector.begin(), sortedVector.end());

	std::vector<int> differences;
	for(unsigned int i = 1; i < sortedVector.size(); ++i)
		differences.push_back(sortedVector[i] - sortedVector[i - 1]);

	return (*(std::min_element(differences.begin(), differences.end())));
}

unsigned int Span::longestSpan()
{
	return (static_cast<unsigned int>(*(max_element(std::begin(_myVector), std::end(_myVector))) - *(min_element(std::begin(_myVector), std::end(_myVector)))));
}

Span::Span(unsigned int num): _size(num)
{
	std::cout << "Span constructor called" << std::endl;
	try{
		_myVector.reserve(_size);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}
