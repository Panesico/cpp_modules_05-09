#pragma once
#include <string>
#include <iostream>
#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	const std::string _target;
public:
	ShrubberyCreationForm(ShrubberyCreationForm &shrubbery);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const &executor) const;
	std::string	getTarget() const;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);