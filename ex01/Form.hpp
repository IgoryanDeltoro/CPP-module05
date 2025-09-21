#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        const int _signGrade;
        const int _executeGrade;
        bool _isSigned;

        Form(const Form &other);
        Form &operator=(const Form &other);

    public:
        Form();
        Form(const std::string n, int sg, int eg);
        ~Form();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        const std::string getName() const;
        bool getIsSign() const;
        int getSignGrade() const;
        int getExetuteGrade() const;
        void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif