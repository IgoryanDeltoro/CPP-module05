#ifndef INTER_HPP
#define INTER_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
    private:
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);

    public:
        Intern();
        ~Intern();

        AForm* makeForm(const std::string &name, const std::string &target) const;
};

#endif