#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define RED "\e[31m"
# define GREEN "\e[32m"
# define RESET "\e[0m\n"
# include <iostream>
# include <bits/stdc++.h>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f);
        void executeForm(AForm const & form) const;

        class GradeTooHighException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
