#include "../include/Bureaucrat.hpp"

void Form::signMe(Bureaucrat &b) {
	_isSigned = 1;
	std::cout << b.getName() << " signed " << getName() << std::endl;
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= getGradeRequired())
		signMe(b);
	else
		throw Form::GradeTooLowException();
}

void Form::setGrade() {
	if (_grade > 150 || _gradeRequired > 150)
		throw Form::GradeTooLowException();
	else if (_grade < 1 || _gradeRequired < 1)
		throw Form::GradeTooHighException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too High");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too Low");
}

Form::Form(int grade) : _name("Default"), _grade(grade), _gradeRequired(42), _isSigned(0)
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
Form::Form() : _name("Default"), _grade(42), _gradeRequired(42), _isSigned(0)
{
	std::cout << "Form default contructor has been called" << std::endl;
}
Form::Form(std::string name, int grade) : _name(name), _grade(grade), _gradeRequired(42), _isSigned(0)
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
Form::Form(std::string name, int grade, int grade_required) : _name(name), _grade(grade), _gradeRequired(grade_required), _isSigned(0)
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
Form::Form(int grade, int grade_required) : _name("Default"), _grade(grade), _gradeRequired(grade_required), _isSigned(0)
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
Form::Form(const Form &Form) : _name(Form._name), _grade(Form._grade), _gradeRequired(Form._gradeRequired), _isSigned(0)
{
	std::cout << "Form copy contructor has been called" << std::endl;
}
Form::Form(std::string name) : _name(name), _grade(42), _gradeRequired(42)
{
	std::cout << "Form name contructor has been called" << std::endl;
}
Form	&Form::operator=(const Form &copy)
{
	std::cout << "Form copy operator has been called" << std::endl;
	if (&copy == this)
		return *this;
	return *this;
}

const std::string	Form::getName() const
{
	return (this->_name);
}

const std::string	Form::getIsSigned() const
{
	if (this->_isSigned)
		return ("\033[32msigned\033[0m");
	else
		return ("\033[31mnot signed\033[0m");
}

bool	Form::getIsSignedBool() const
{
	return (this->_isSigned);
}

int	Form::getGradeRequired() const
{
	return (this->_grade);
}

int	Form::getGrade() const
{
	return (this->_gradeRequired);
}

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	  ":\ngrade:" << a->getGrade() <<
	  "\ngrade-required:" << a->getGradeRequired() <<
	  "\nis " << a->getIsSigned() <<
	  std::endl;
	return (o);
}

Form::~Form()
{
	std::cout << "Form destructor has been called" << std::endl;
}