#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("") {
    std::cout << "RobotomyRequestForm default constructor called.\n";
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm parameterized constructor.\n";
    std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called.\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);
    
    std::cout << "BZZZZZZ.. driling nose!\n";
    if(std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!\n";
    } else {
        std::cout << "The robotomy was failed on " << _target << std::endl;
    }
}