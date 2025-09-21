#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm: public AForm {
    private:
        std::string _target;

        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;

        class AnErrorMessageException: public std::exception {
            private:
                std::string _errorMessage;
            public:
                AnErrorMessageException(const std::string &message);
                ~AnErrorMessageException() throw();
                virtual const char *what() const throw();
        };
};

#endif