#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        const int _signGrade;
        const int _executeGrade;
        bool _isSigned;

        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

    public:
        AForm();
        AForm(const std::string n, int sg, int eg);
        virtual ~AForm();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        const std::string getName() const;
        bool getSignState() const;
        int getSignGrade() const;
        int getExetuteGrade() const;
        bool beSigned(const Bureaucrat &b);
        void checkExecution(const Bureaucrat &execution) const;
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif