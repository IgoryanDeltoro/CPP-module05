#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(0){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    if (_grade < 0) {
        throw Bureaucrat::GradeTooLowException(); 
    } else if (_grade > 150) {
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::setGradeDown(int grade) {
    if (grade < 0) return ;
    if ((this->_grade - grade) < 0) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->_grade -= grade; 
    }
}

void Bureaucrat::setGradeUp(int grade) {
    if (grade < 0) return ;
    if ((grade + _grade) > 150) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        this->_grade += grade; 
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}