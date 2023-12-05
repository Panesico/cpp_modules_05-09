#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class numNotFound: public std::exception
{
public:
	char const * what() const throw()
	{
		return "Number not found!";
	}
};

template<typename T>
int	*easyfind(T &vector, int num)
{
	typename T::iterator iter;

	if ((iter = std::find(vector.begin(), vector.end(), num)) == vector.end())
		throw numNotFound();
	return (&(*iter));
}
