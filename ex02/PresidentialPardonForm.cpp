#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("") {
    std::cout << "PresidentialPardonForm default constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm parameterized constructor.\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called.\n";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}