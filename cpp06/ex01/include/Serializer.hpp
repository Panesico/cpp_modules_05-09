#pragma once
#include <iostream>
#include <iomanip>
#include <limits>

typedef struct myData
{
	int myInt;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(const std::string input);
public:
	~Serializer();
	Serializer &operator=(const Serializer &src);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
