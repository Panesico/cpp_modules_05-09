#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor for target " << this->getTarget() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;

	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor " << this->getName() << " called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

static int robot_fail = 0;

void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if (executor.getGrade() > this->getGradeRequired())
		throw (Bureaucrat::GradeTooLowException());
	else if (!getIsSignedBool())
		throw (AForm::FormNotSignedException());
	else if (robot_fail++ % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Form " << a->getName() <<
	  ":\n\tgrade:\t" << a->getGrade() <<
	  "\n\tgradeRequired:\t" << a->getGradeRequired() <<
	  "\n\tis signed:\t" << a->getIsSigned() <<
	  std::endl;
	return (o);
}