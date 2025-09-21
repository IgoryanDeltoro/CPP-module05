#include "ShrubberyCreationForm.hpp"
#include <dirent.h>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(), _target(""){
    std::cout << "ShrubberyCreationForm default constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationFor", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm parameterized constructor called.\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called.\n";
}

ShrubberyCreationForm::AnErrorMessageException::AnErrorMessageException(const std::string &message) : _errorMessage(message) {}

ShrubberyCreationForm::AnErrorMessageException::~AnErrorMessageException() throw() {}


const char *ShrubberyCreationForm::AnErrorMessageException::what() const throw() {
    return _errorMessage.c_str();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);
    
    std::string fname = _target + "__shrubbery";
    std::ofstream outfile(fname.c_str());

    if (!outfile.is_open()) {
        throw ShrubberyCreationForm::AnErrorMessageException("Error: could not open file.");
    }
    outfile <<  "   ccee88oo\n"
                " C8O8O8Q8PoOb o8oo\n"
                " dOB69QO8PdUOpugoO9bD\n"
                "CgggbU8OU qOp qOdoUOdcb\n"
                "    6OuU  /p u gcoUodpP\n"
                "      \\\\\\//  /douUP\n"
                "        \\\\\\////                /___/\n"
                "         |||/\\|                ('\')\n"
                "         |||\\/          _______//\n"
                "         ||||||         / |||||/\n"
                "   .....//||||\\...........||.||.............................\n";

    outfile.close();
}
