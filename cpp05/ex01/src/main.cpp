#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

/* void ft_leaks()
{
	system("leaks -q Form");
} */

int main(void)
{
	/* atexit(ft_leaks); */
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new Form();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		try {
			b->beSigned(*a);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new Form("Rent Contract", 140, 100);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;

		a->signForm(*c);

		std::cout << c;
		try {
			c->beSigned(*a);
		} catch (std::exception &e) { std::cout << e.what() << std::endl;}

		std::cout << c;

		b->signForm(*c);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Form *a = NULL;

		a = new Form(160, 145);
		delete a;

		a = new Form(145, 160);
		delete a;

		a = new Form(-15, 145);
		delete a;

		a = new Form(145, -15);
		std::cout << std::endl;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	return (0);
}