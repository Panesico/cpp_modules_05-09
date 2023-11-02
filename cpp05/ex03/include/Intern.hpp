#pragma once

#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
public:
	Intern();
	Intern(const Intern &copy);
	Intern	&operator=(const Intern &copy);
	~Intern();

	AForm *makeForm(const std::string form, const std::string target);
};