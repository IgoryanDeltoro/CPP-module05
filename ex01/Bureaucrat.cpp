#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat parameterized constructor called.\n";
    if (_grade < 1) {
        throw GradeTooHighException();
    } else if (_grade > 150) {
        throw GradeTooLowException(); 
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called.\n";
}

const std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::signForm(Form &f) {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl; 
    } catch(const std::exception& e) {
        std::cerr << _name << "  couldn't sign " << f.getName() << " becouse " << e.what() << '\n';
    }
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}