#include <iostream>
#include "../include/Bureaucrat.hpp"

int main()
{
    std::cout << "\033[32mTest 1\033[0m" << std::endl;
    {
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        Bureaucrat *a = new Bureaucrat();
        std::cout << std::endl;

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        std::cout << a;

        a->incrementGrade();

        std::cout << a;

        a->decrementGrade();

        std::cout << a;

        a->decrementGrade();

        std::cout << a;
        std::cout << std::endl;

        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
        delete a;
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "\033[32mTest 2\033[0m" << std::endl;
    {
        std::cout << std::endl;
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        Bureaucrat *a = new Bureaucrat(1);
        std::cout << std::endl;
        std::cout << "\033[34mTesting\033[0m" << std::endl;
        std::cout << a;

        a->decrementGrade();

        std::cout << a;

        a->incrementGrade();

        std::cout << a;

        a->incrementGrade();

        std::cout << a;
        std::cout << std::endl;

        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
        delete a;
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "\033[32mTest 3\033[0m" << std::endl;
    {
        std::cout << std::endl;
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        Bureaucrat *a = new Bureaucrat(0);

        if (a != NULL)
        {
            std::cout << std::endl;

            std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
            delete a;
        }

        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "\033[32mTest 4\033[0m" << std::endl;
    {
        std::cout << std::endl;
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        Bureaucrat *a = NULL;

        a = new Bureaucrat(151);

        if (a != NULL)
        {
            std::cout << std::endl;
            std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
            delete a;
        }
        std::cout << std::endl;
    }
}