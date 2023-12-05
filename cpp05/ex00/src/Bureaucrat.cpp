#include "../include/Bureaucrat.hpp"
#include <iostream>

void    Bureaucrat::incrementGrade() {
    try {
        setGrade(_grade - 1);
    }
    catch (GradeTooHighException &e)
    {
        std::cerr << "\033[31mIncrementing the grade of " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << "\033[31mDecrementing the grade of " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
    }
    catch (...)
    {
        std::cerr << "\033[31mDecrementing the grade of " << getName() << " failed: " << "Unkown exception" << "\033[0m" << std::endl;
    }
}

void    Bureaucrat::decrementGrade() {
    try {
        setGrade(_grade + 1);
    }
    catch (GradeTooHighException &e)
    {
        std::cerr << "\033[31mIncrementing the grade of " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << "\033[31mDecrementing the grade of " << getName() << " failed: " << e.what() << "\033[0m" << std::endl;
    }
    catch (...)
    {
        std::cerr << "\033[31mDecrementing the grade of " << getName() << " failed: " << "Unkown exception" << "\033[0m" << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too Low");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
    o << "Bureaucrat " << a->getName() << ":" << std::endl << "\tgrade: " << a->getGrade() << std::endl;
    return (o);
}

void Bureaucrat::setGrade(int grade) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default")
{
	std::cout << "Bureaucrat grade contructor has been called" << std::endl;
	try {
		setGrade(grade);
	} catch (std::exception &e) { std::cout << e.what() << std::endl;}
}
Bureaucrat::Bureaucrat() : _name("Default"), _grade(42)
{
	std::cout << "Bureaucrat default contructor has been called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat default contructor has been called" << std::endl;
	try {
		setGrade(grade);
	} catch (std::exception &e) { std::cout << e.what() << std::endl;}
}
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name)
{
	std::cout << "Bureaucrat copy contructor has been called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(42)
{
	std::cout << "Bureaucrat name contructor has been called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat copy operator has been called" << std::endl;
    if (this != &copy)
        this->_grade = copy.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor has been called" << std::endl;
}