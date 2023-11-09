#include "../include/iter.hpp"

void ft_toLower(char &a)
{
	a = std::tolower(static_cast<unsigned char>(a));
}

void ft_toUpper(char &a)
{
	a = std::toupper(static_cast<unsigned char>(a));
}

int main( void ) {
	char a[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Calling toupper: ";
	::iter(a, sizeof(a), ft_toUpper);
	std::cout << a << std::endl;
	std::cout << "Calling tolower: ";
	::iter(a, sizeof(a), ft_toLower);
	std::cout << a << std::endl;
	return 0;
}
