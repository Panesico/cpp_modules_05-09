#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class AForm{
protected:
	const std::string	_name;
	bool				_isSigned;
	const int			_grade;
	const int			_gradeRequired;
public:
	AForm();
	AForm(const AForm &bureaucrat);
	AForm(std::string name);
	AForm(int grade);
	AForm(std::string name, int grade);
	AForm(std::string name, int grade, int grade_required);
	AForm(int grade, int grade_required);
	AForm	&operator=(const AForm &copy);
	virtual ~AForm();

	bool	getIsSignedBool() const;
	const std::string	getIsSigned() const;
	const std::string	getName() const;
	int	getGradeRequired() const;
	int	getGrade() const;

	void setGrade();
	void beSigned(Bureaucrat &b);
	void signMe(Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor)const = 0;

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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm *a);