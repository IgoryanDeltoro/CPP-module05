#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Inter.hpp"
#include <stdexcept>

int main () {
{
    AForm* rrf = NULL;
    try
    {
        std::cout << GREEN << "\n============ Shrubbery creating test ==========\n" << RESET;
        Intern someRandomIntern;
        Bureaucrat br("Alice", 1);
        rrf = someRandomIntern.makeForm("Shrubbery creation", "Who");
        if (!rrf)
            throw std::invalid_argument("Error: makeForme returned: (null)\n");
        std::cout << rrf->getName() << std::endl;
        rrf->beSigned(br);
        rrf->execute(br);
        delete rrf;
        rrf = NULL;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << RED << "\n============ Shrubbery creating error test (the name is not exist) ==========\n" << RESET;
        Intern someRandomIntern;
        Bureaucrat br("Alice", 1);
        rrf = someRandomIntern.makeForm("Shrubbery reation", "Who");
        if (!rrf)
            throw std::invalid_argument("Error: makeForme returned: (null)\n");
        std::cout << rrf->getName() << std::endl;
        rrf->beSigned(br);
        rrf->execute(br);
        delete rrf;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        if (rrf)
            delete rrf;
    }
}
{ 
    AForm* rrf = NULL;
    try
    {
        std::cout<< GREEN << "\n============ Presidential pardon test (wrong name) ==========\n" << RESET;
        Intern someRandomIntern;
        Bureaucrat br("Jacob", 5);
        rrf = someRandomIntern.makeForm("   Presidential pardon          ", "Bender");
        if (!rrf)
            throw std::invalid_argument("Error: makeForme returned: (null)\n");
        std::cout << rrf->getName() << std::endl;
        rrf->beSigned(br);
        rrf->execute(br);
        delete rrf;
        rrf = NULL;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout  << RED << "\n============ Presidential pardon erro test (too low grade) ==========\n" << RESET;
        Intern someRandomIntern;
        Bureaucrat br("Jacob", 100);
        rrf = someRandomIntern.makeForm("   Presidential pardon          ", "Bender");
        if (!rrf)
            throw std::invalid_argument("Error: makeForme returned: (null)\n");
        std::cout << rrf->getName() << std::endl;
        rrf->beSigned(br);
        rrf->execute(br);
        delete rrf;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        if (rrf)
            delete rrf;
    }
}
{ 
    AForm* rrf = NULL;
    try
    {
        std::cout<< GREEN << "\n============ Robotomy request test ==========\n"<< RESET;
        Intern someRandomIntern;
        Bureaucrat br("Bob", 5);
        rrf = someRandomIntern.makeForm("Robotomy request", "Linda");
        if (!rrf)
            throw std::invalid_argument("Error: makeForme returned: (null)\n");
        std::cout << rrf->getName() << std::endl;
        rrf->beSigned(br);
        rrf->execute(br);
        delete rrf;
        rrf = NULL;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout  << RED << "\n============ Presidential pardon erro test (try to incremebt grade) ==========\n" << RESET;
        Intern someRandomIntern;
        Bureaucrat br("Bob", 1);
        rrf = someRandomIntern.makeForm("   Presidential pardon          ", "Linda");
        if (!rrf)
            throw std::invalid_argument("Error: makeForme returned: (null)\n");
        std::cout << rrf->getName() << std::endl;
        rrf->beSigned(br);
        br.incrementGrade();
        rrf->execute(br);
        delete rrf;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        if (rrf)
            delete rrf;
    }
}
    std::cout  << "\n============ end of test ==========\n";
    return 0;
}