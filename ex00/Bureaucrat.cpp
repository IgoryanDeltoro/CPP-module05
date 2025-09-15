#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(0) {}
Bureaucrat ::~Bureaucrat(){}


std::string Bureaucrat::getName() const {
    return this->_name;
}
int Bureaucrat::getGrade() {
    return this->_grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
    os << b.getName();
    return os;
}