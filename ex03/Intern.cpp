#include "Inter.hpp"
#include <bits/stdc++.h>

std::string trim(std::string str);
std::string toLowerCase(std::string str);

Intern::Intern() {
    std::cout << "Intern default constructor called.\n";
}

Intern::~Intern() {
    std::cout << "Intern destructor called.\n";
}

static AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

static AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) const {
    std::string names[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    typedef AForm* (*FormCreator)(const std::string &target); 
    FormCreator forms[] = {createShrubbery, createPardon, createRobotomy}; 
    std::string converted_str = toLowerCase(trim(name));

    AForm* res = NULL;
    size_t idx = -1;
    for (int i = 0; i < 3; i++) {
        if ((idx = converted_str.find(names[i])) != std::string::npos) {
            std::cout << "Intern creates " << names[i] << std::endl;
            res = forms[i](target);
            break;
        }
    }
    if (!res)
        std::cout << name <<  " doesn't exist.\n";
    return res;
}

std::string trim(std::string str) {
    int start = 0;
    int end = str.length();

    for (int i = 0; str[i]; i++) {
        if (str[i] == 32 || str[i] == 32)
            start++;
        else
            break;
    }
    for (int i = end; str[i]; i--) {
        if (str[i] == 32 || str[i] == 32)
            end--;
        else
            break;
    }
    return str.substr(start, static_cast<size_t>(end - start));
}

std::string toLowerCase(std::string str) {
    std::string res;
    for (int i = 0; str[i]; i++) {
        res += tolower(str[i]);
    }
    return res;
}