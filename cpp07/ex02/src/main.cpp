#include "../include/Array.hpp"

int main( void ) {

	Array<int> myArray(123);
	Array<int> anotherArray;

	int *hello = myArray.getArray();
	std::cout << hello[0] << std::endl;
	myArray.setValue(3, 123);
	std::cout << myArray[3] << std::endl;

	anotherArray.setValue(4, 65);
	std::cout << anotherArray[4] << std::endl;
	anotherArray.setValue(65, 99);
	std::cout << anotherArray[65] << std::endl;

	return 0;
}
