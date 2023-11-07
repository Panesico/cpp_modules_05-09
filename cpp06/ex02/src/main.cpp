#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

static Base * generate(void)
{

	std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds nanoTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime.time_since_epoch());

	uint64_t randomNumber = static_cast<uint64_t>(nanoTime);

	randomNumber = randomNumber % 3;

	switch (randomNumber)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			std::cout << "Error" << std::endl;
			return 0;
	}
}

static void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A class" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B class" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C class" << std::endl;
	else
		std::cout << "Unkown class type" << std::endl;
}

//static void identify(Base& p);

int main()
{
	Base* myBasePtr = generate();
	if (!myBasePtr)
		return 0;

	identify(myBasePtr);
}
