#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm{
private:
	const std::string _target;
public:
	PresidentialPardonForm(PresidentialPardonForm &copy);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	void	execute(Bureaucrat const &executor) const;
	std::string	getTarget() const;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);