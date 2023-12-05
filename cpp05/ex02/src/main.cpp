#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void ft_leaks()
{
	system("leaks -q Forms");
}

int main(void)
{
	atexit(ft_leaks);
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		AForm *b = new PresidentialPardonForm("Clown");
		AForm *c = new RobotomyRequestForm("Bender");
		AForm *d = new ShrubberyCreationForm("Christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << std::endl;

		try {
			b->beSigned(*a);
			b->execute(*a);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		try {
			c->beSigned(*a);
			c->execute(*a);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		try {
			d->beSigned(*a);
			d->execute(*a);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		std::cout << std::endl;
		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		delete d;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new PresidentialPardonForm("some dude");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		try {
			c->execute(*b);
			c->beSigned(*a);
			a->signForm(*c);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}
		std::cout << std::endl;
		std::cout << c;
		std::cout << std::endl;
		try {
			c->beSigned(*b);
			b->signForm(*c);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		std::cout << std::endl;
		std::cout << c;
		std::cout << std::endl;

		try {
			std::cout << std::endl;
			b->signForm(*c);
			std::cout << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		try {
			c->execute(*a);
			a->executeForm(*c);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		try {
			std::cout << std::endl;

			c->execute(*b);
			b->executeForm(*c);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("gei", 1);
		AForm *b = new RobotomyRequestForm("ZA WARUDO");
		AForm *c = new ShrubberyCreationForm("Pepe");
		std::cout << std::endl;

		try {
			b->beSigned(*a);
			a->signForm(*c);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		std::cout << std::endl;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		try {
			for (int i= 0; i < 10; i++)
				b->execute(*a);
			a->executeForm(*c);
			c->execute(*a);
			std::cout << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	return (0);
}