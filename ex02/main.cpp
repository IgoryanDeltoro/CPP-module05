#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main () {
    {
    std::cout << "\n======== Test of a bureaucrat's work with the occurrence of an error. =======\n\n";
        AForm *s;
        AForm *r;
        AForm *p;
    try {
        Bureaucrat alice("Alice", 1);
        s = new ShrubberyCreationForm("home");
        r = new RobotomyRequestForm("Bender");
        p = new PresidentialPardonForm("Ford Prefect");

        std::cout << "\n======== Test of form of ShrubberyCreationForm. =======\n";

        alice.signForm(*s);
        s->execute(alice);
        alice.executeForm(*s);

        std::cout << "\n======== Test of form of RobotomyRequestForm. =======\n";

        alice.signForm(*r);
        alice.executeForm(*r);

        std::cout << "\n======== Test of form of PresidentialPardonForm. =======\n";

        alice.signForm(*p);
        alice.signForm(*p);
        alice.executeForm(*p);

        std::cout << "\n======== End of test. =======\n";
        delete s;
        delete r;
        delete p;

    } catch (const std::exception& e) {
        std::cout << "\n======== End of test. =======\n";
        std::cerr << RED << e.what() << RESET;
        if (s)
            delete s;
        if (r)
            delete r;
        if (p)
            delete p;
    }
   }
    return 0;
}