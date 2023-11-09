#pragma once
#include <iostream>

template<typename T, typename U>
void iter(T* array, size_t len, U (*func)(T&))
{
	if (!array || !len)
		return ;
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}
