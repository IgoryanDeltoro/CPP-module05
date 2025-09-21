#include "Form.hpp"

Form::Form() : _name(""), _signGrade(150), _executeGrade(150), _isSigned(false) {
    std::cout << "Form default constructor called.\n";
}

Form::Form(const std::string n, int sg, int eg) : _name(n), _signGrade(sg), _executeGrade(eg), _isSigned(false) {
    std::cout << "Form parameterized constructor called.\n";
    if (_signGrade < 1 || _executeGrade < 1)
        Form::GradeTooHighException();
    if (_signGrade > 150 || _executeGrade > 150)
        Form::GradeTooLowException();
}

Form::~Form() {
    std::cout << "Form destructor called.\n";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const std::string Form::getName() const {
    return _name;
}

bool Form::getIsSign() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExetuteGrade() const {
    return _executeGrade;
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator << (std::ostream &os, const Form &f) {
    os << f.getName();
    return os;
}