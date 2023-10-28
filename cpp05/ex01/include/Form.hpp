#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class Form{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_grade;
	const int			_gradeRequired;
public:
	Form();
	Form(const Form &bureaucrat);
	Form(std::string name);
	Form(int grade);
	Form(std::string name, int grade);
	Form(std::string name, int grade, int grade_required);
	Form(int grade, int grade_required);
	Form	&operator=(const Form &copy);
	~Form();

	bool	getIsSignedBool() const;
	const std::string	getIsSigned() const;
	const std::string	getName() const;
	int	getGradeRequired() const;
	int	getGrade() const;

	void setGrade(int grade, int gradeRequired);
	void beSigned(Bureaucrat &b);

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

std::ostream	&operator<<(std::ostream &o, Form *a);