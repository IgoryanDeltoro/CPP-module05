#include "Bureaucrat.hpp"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define RESET "\e[0m\n"

int main () {
   {
    std::cout << "\n======== Test number one without an error. =======\n\n";
    try {
        Bureaucrat b1("Alice", 1);
        b1.decrementGrade();
       
        std::cout << GREEN  << b1 << RESET << '\n';

        Bureaucrat b2;
        b2 = b1;
        b2.incrementGrade();
        std::cout << GREEN  << b2 << RESET << '\n';

        Bureaucrat b3 = b1;
        b3.incrementGrade();; 
        std::cout << GREEN  << b3 << RESET << '\n';

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << '\n';
    }
   }
    {
    std::cout << "\n======== Test number two with an error. =======\n\n";
    try {
        Bureaucrat b1("Michael", 155);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    try {
        Bureaucrat b2("Michael", 0);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    try {
        Bureaucrat b3("Michael", 150);
        b3.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << '\n';
    }
        try {
        Bureaucrat b3("Michael", 1);
        b3.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << '\n';
    }
   }
    return 0;
}