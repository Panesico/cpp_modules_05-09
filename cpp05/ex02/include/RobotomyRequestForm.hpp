#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{
private:
	const std::string _target;
public:
	RobotomyRequestForm(RobotomyRequestForm &copy);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const &executor) const;
	std::string	getTarget() const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);