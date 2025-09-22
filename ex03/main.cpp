#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Inter.hpp"
#include <stdexcept>

int main () {
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("   Presidential Pardon          ", "Bender");
        if (!rrf)
            throw std::invalid_argument("Error: makeForme returned: (null)\n");
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