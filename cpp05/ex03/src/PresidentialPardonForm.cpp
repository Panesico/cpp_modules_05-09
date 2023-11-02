#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor for target " << this->getTarget() << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;

	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor " << this->getName() << " called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	if (executor.getGrade() > this->getGradeRequired())
		throw (Bureaucrat::GradeTooLowException());
	else if (!getIsSignedBool())
		throw (AForm::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << "Form " << a->getName() <<
	  ":\n\tgrade:\t" << a->getGrade() <<
	  "\n\tgradeRequired:\t" << a->getGradeRequired() <<
	  "\n\tis signed:\t" << a->getIsSigned() <<
	  std::endl;
	return (o);
}