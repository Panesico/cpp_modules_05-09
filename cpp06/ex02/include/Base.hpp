#pragma once
#include <iostream>
#include <iomanip>
#include <limits>
#include <chrono>

class Base
{
protected:

public:
	virtual ~Base();
	Base * generate(void);
};
