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

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
