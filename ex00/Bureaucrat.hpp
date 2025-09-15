#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <bits/stdc++.h>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat(const std::string name);
        ~Bureaucrat();


        std::string getName() const;
        int getGrade();
};

std::ofstream &operator<<(std::ofstream &os, const Bureaucrat &b);

#endif