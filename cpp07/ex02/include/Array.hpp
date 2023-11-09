#pragma once
#include <iostream>

template<typename T>
class Array{
private:
	T* _array;
	unsigned int _size;
public:
	Array()
	{
		_array = new T[64];
		_size = 64;
	}
	Array(unsigned int n)
	{
		_array = new T[n];
		_size = n;
	}
	Array(Array &copy)
	{
		_array = new T[copy.size()];
		_size = copy.size();
	}
	Array& operator=(Array &copy){
		if (*this != copy)
		{
			_array = new T[copy.size()];
			_size = copy.size();
		}
		return *this;
	}
	T operator[](unsigned int num){
		try {
			if (num > size())
				throw OutOfBounds();
			return (_array[num]);
		}
		catch (OutOfBounds &e)
		{
			std::cout << e.what() << std::endl;
			std::exit(1);
		}
	}
	~Array() {delete[] _array;}

	unsigned int size(){
		return (_size);
	}
	T *getArray(){
		return (_array);
	}

	void setValue(unsigned int pos, T value)
	{
		try {
			if (pos > size())
				throw OutOfBounds();
			_array[pos] = value;
		}
		catch (OutOfBounds &e)
		{
			std::cout << e.what() << std::endl;
			std::exit(1);
		}
	}

	class OutOfBounds : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Out of bounds!");
		}
	};
};
