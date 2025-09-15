#include "Bureaucrat.hpp"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define RESET "\e[0m\n"

int main () {
   {
     try {

        Bureaucrat b1("Alice", 42);
        b1.setGradeUp(100);
        b1.setGradeUp(9);
        std::cout << GREEN  << b1 << RESET << '\n';

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << '\n';
    }
   }
    {
     try {
        
        Bureaucrat b1("Alice", 42);
        b1.setGradeDown(40);
        b1.setGradeDown(-3);
        std::cout << GREEN  << b1 << RESET << '\n';

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << '\n';
    }
   }
    return 0;
}