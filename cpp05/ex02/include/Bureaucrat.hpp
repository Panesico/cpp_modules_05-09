#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat {
private:
	const std::string _name;
	int	_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat(std::string name);
    Bureaucrat(int grade);
    Bureaucrat(std::string name, int grade);
	Bureaucrat	&operator=(const Bureaucrat &copy);
	~Bureaucrat();

    int         getGrade() const;
    std::string getName() const;
    void        setGrade(int grade);
	void 		signForm(AForm &f);
	void		executeForm(AForm &form) const;
	void		canExtecute(AForm &form) const;

    void    incrementGrade();
    void    decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);