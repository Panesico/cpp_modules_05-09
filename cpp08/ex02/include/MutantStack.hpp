#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
private:
	std::vector<T> _myVector;
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack()
	{
		std::cout << "MutantStack constructor called" << std::endl;
	};
	MutantStack(const MutantStack &copy) : std::stack<T>(copy)
	{
		std::cout << "MutantStack copy contructor called" << std::endl;
		*this = copy;
	}
	MutantStack		&operator=(MutantStack const &src) {
		std::cout << "MutantStack equal operator called" << std::endl;
		std::stack<T>::operator=(src);
		return *this;
	}
	~MutantStack() {
		std::cout << "MutantStack destructor called" << std::endl;
	};
	iterator	begin(void) {
		return this->c.begin();
	}
	iterator	end(void) {
		return this->c.end();
	}
};
