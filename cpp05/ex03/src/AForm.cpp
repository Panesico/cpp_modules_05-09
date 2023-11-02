#include "../include/Bureaucrat.hpp"

void AForm::signMe(Bureaucrat &b) {
	_isSigned = 1;
	std::cout << b.getName() << " signed " << getName() << std::endl;
}

void AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() >= getGradeRequired())
		signMe(b);
	else
		throw AForm::GradeTooLowException();
}

void AForm::setGrade() {
	if (_grade > 150 || _gradeRequired > 150)
		throw AForm::GradeTooLowException();
	else if (_grade < 1 || _gradeRequired < 1)
		throw AForm::GradeTooHighException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too High");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too Low");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
};

AForm::AForm(int grade) : _name("Default"), _grade(grade), _gradeRequired(42)
{
	try
	{
		setGrade();
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
	catch (...)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << "Unkown exception" << "\033[0m" << std::endl;
	}
	std::cout << "Form grade contructor has been called" << std::endl;
}
AForm::AForm() : _name("Default"), _grade(42), _gradeRequired(42)
{
	std::cout << "Form default contructor has been called" << std::endl;
}
AForm::AForm(std::string name, int grade) : _name(name), _grade(grade), _gradeRequired(42)
{
	try
	{
		setGrade();
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
	catch (...)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << "Unkown exception" << "\033[0m" << std::endl;
	}
	std::cout << "Form default contructor has been called" << std::endl;
}
AForm::AForm(std::string name, int grade, int grade_required) : _name(name), _grade(grade), _gradeRequired(grade_required)
{
	try
	{
		setGrade();
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
	catch (...)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << "Unkown exception" << "\033[0m" << std::endl;
	}
	std::cout << "Form default contructor has been called" << std::endl;
}
AForm::AForm(int grade, int grade_required) : _name("Default"), _grade(grade), _gradeRequired(grade_required)
{
	try
	{
		setGrade();
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
	catch (...)
	{
		std::cerr << "\033[31mCreating Bureaucrat " << getName() << " failed: " << "Unkown exception" << "\033[0m" << std::endl;
	}
	std::cout << "Form default contructor has been called" << std::endl;
}
AForm::AForm(const AForm &Form) : _name(Form._name), _grade(Form._grade), _gradeRequired(Form._gradeRequired)
{
	std::cout << "Form copy contructor has been called" << std::endl;
}
AForm::AForm(std::string name) : _name(name), _grade(42), _gradeRequired(42)
{
	std::cout << "Form name contructor has been called" << std::endl;
}
AForm	&AForm::operator=(const AForm &copy)
{
	std::cout << "Form copy operator has been called" << std::endl;
	if (&copy == this)
		return *this;
	return *this;
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

const std::string	AForm::getIsSigned() const
{
	if (this->_isSigned)
		return ("\033[32msigned\033[0m");
	else
		return ("\033[31mnot signed\033[0m");
}

bool	AForm::getIsSignedBool() const
{
	return (this->_isSigned);
}

int	AForm::getGradeRequired() const
{
	return (this->_grade);
}

int	AForm::getGrade() const
{
	return (this->_gradeRequired);
}

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "Form " << a->getName() <<
	  ":\ngrade:" << a->getGrade() <<
	  "\ngrade-required:" << a->getGradeRequired() <<
	  "\nis " << a->getIsSigned() <<
	  std::endl;
	return (o);
}

AForm::~AForm()
{
	std::cout << "Form destructor has been called" << std::endl;
}