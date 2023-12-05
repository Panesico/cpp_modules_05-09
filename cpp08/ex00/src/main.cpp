#include "../include/easyfind.hpp"

int main( void ) {
	std::vector<int> myVec;

	try{
		myVec.push_back(1);
		myVec.push_back(2);
		myVec.push_back(3);
		myVec.push_back(4);
		myVec.push_back(6);
		std::cout << *(easyfind(myVec, 6)) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try{
		myVec.push_back(1);
		myVec.push_back(2);
		myVec.push_back(3);
		myVec.push_back(4);
		myVec.push_back(6);
		std::cout << easyfind(myVec, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
