#include "../include/Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const std::string input)
{
	std::cout << "Serializer Constructor for " << input << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer Deconstructor called" << std::endl;
}

unsigned long Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<unsigned long>(ptr);
}
Data* Serializer::deserialize(unsigned long raw)
{
	return reinterpret_cast<Data*>(raw);
}
