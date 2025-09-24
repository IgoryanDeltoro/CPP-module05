#include "AForm.hpp"

AForm::AForm() : _name(""), _signGrade(150), _executeGrade(150), _isSigned(false) {
    std::cout << "AForm default constructor called.\n";
}

AForm::AForm(const std::string n, int sg, int eg) : _name(n), _signGrade(sg), _executeGrade(eg), _isSigned(false) {
    std::cout << "AForm parameterized constructor called.\n";
    if (_signGrade < 1 || _executeGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _executeGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {
    std::cout << "AForm destructor called.\n";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

const std::string AForm::getName() const {
    return _name;
}

bool AForm::getSignState() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExetuteGrade() const {
    return _executeGrade;
}

bool AForm::beSigned(const Bureaucrat &b) {
    if (_isSigned) {
        std::cout << b.getName() << " form was signed.\n";
        return false;
    }
    if (b.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw GradeTooLowException();
    return true;
}

void AForm::checkExecution(const Bureaucrat &execution) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (execution.getGrade() > _executeGrade)
        throw GradeTooLowException();
}

std::ostream &operator << (std::ostream &os, const AForm &f) {
    os << f.getName();
    return os;
}