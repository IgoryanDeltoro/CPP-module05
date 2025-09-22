#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Inter.hpp"

int main () {
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("   Presidential Pardon          ", "Bender");
        if (!rrf)
            throw std::exception();
        std::cout << rrf->getName() << std::endl;
        delete rrf;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    

}

    return 0;
}