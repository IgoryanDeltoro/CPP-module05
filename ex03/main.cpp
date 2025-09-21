#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Inter.hpp"

int main () {
//    {
//     std::cout << "\n======== Test Bureaucrat's work. =======\n\n";
//     try {
//         Bureaucrat alice("Alice", 1);
//         AForm *s = new ShrubberyCreationForm("home");
//         AForm *r = new RobotomyRequestForm("Bender");
//         AForm *p = new PresidentialPardonForm("Ford Prefect");

//         std::cout << "\n======== Test form of ShrubberyCreationForm. =======\n";

//         alice.signForm(*s);
//         s->execute(alice);
//         alice.executeForm(*s);

//         std::cout << "\n======== Test form of RobotomyRequestForm. =======\n";

//         alice.signForm(*r);
//         alice.executeForm(*r);

//         std::cout << "\n======== Test form of PresidentialPardonForm. =======\n";

//         alice.signForm(*p);
//         alice.signForm(*p);
//         alice.executeForm(*p);

//         std::cout << "\n======== End of test. =======\n";
//         delete s;
//         delete r;
//         delete p;

//     } catch (const std::exception& e) {
//         std::cerr << RED << e.what() << RESET;
//     }
//    }

{
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("     Pardon            ", "Bender");
    std::cout << rrf->getName() << std::endl;
}

    return 0;
}