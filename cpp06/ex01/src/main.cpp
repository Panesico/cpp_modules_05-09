#include "../include/Serializer.hpp"

int main()
{
	Data *ptr_data = new Data;
	uintptr_t ptr_raw = Serializer::serialize(ptr_data);

	std::cout << "Im ptr_data: " << ptr_data << std::endl;
	std::cout << "Im ptr_raw: " << ptr_raw << std::endl << std::endl;

	ptr_data = 0;

	std::cout << "Im ptr_data: " << ptr_data << std::endl;
	std::cout << "Im ptr_raw: " << ptr_raw << std::endl << std::endl;

	ptr_data = Serializer::deserialize(ptr_raw);

	std::cout << "Im ptr_data: " << ptr_data << std::endl;
	std::cout << "Im ptr_raw: " << ptr_raw << std::endl;
}
