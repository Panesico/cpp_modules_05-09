#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;

	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor " << this->getName() << " called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
	if (executor.getGrade() > this->getGradeRequired())
		throw (Bureaucrat::GradeTooLowException());
	else if (!getIsSignedBool())
		throw (AForm::FormNotSignedException());
	else
	{
		std::ofstream outfile ((this->getTarget() + "_shrubbery").c_str());
		outfile <<   "              v .   ._, |_  .,\n"
					 "           `-._\\/  .  \\ /    |/_\n"
					 "               \\\\  _\\, y | \\//\n"
					 "         _\\_.___\\\\, \\\\/ -.\\||\n"
					 "           `7-,--.`._||  / / ,\n"
					 "           /'     `-. `./ / |/_.'\n"
					 "                     |    |//\n"
					 "                     |_    /\n"
					 "                     |-   |\n"
					 "                     |   =|\n"
					 "                     |    |\n"
					 "--------------------/ ,  . \\--------._" << std::endl;
		outfile.close();
	}
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() <<
	  ":\n\tgrade:\t" << a->getGrade() <<
	  "\n\tgradeRequired:\t" << a->getGradeRequired() <<
	  "\n\tis signed:\t" << a->getIsSigned() <<
	  std::endl;
	return (o);
}