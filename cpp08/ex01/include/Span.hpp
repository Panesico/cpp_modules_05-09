#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Span{
private:
	unsigned int _size;
	std::vector<int> _myVector;
	Span();
public:
	Span(unsigned int num);
	~Span();
	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};
