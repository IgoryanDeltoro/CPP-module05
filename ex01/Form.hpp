#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
    public:
        Form();
        Form(const std::string n, int sg, int eg);
        Form(const Form &other);
        Form &operator=(const Form &other);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        const std::string getName();
        bool getIsSign();
        const int getSignGrade();
        const int getExetuteGrade();
        void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif