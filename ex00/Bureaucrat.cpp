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

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called.\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "Bureaucrat assignment operator called.\n";
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
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
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &b) {
    if (b.getName().length() != 0)
        os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    else
        os << "Bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}