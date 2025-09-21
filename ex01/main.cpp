#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED "\e[31m"
#define GREEN "\e[32m"
#define RESET "\e[0m\n"

int main () {
   {
    std::cout << "\n======== Test number one without an error. =======\n\n";
    try {
        Bureaucrat b1("Alice", 50);
        b1.decrementGrade();
        Form f1("Rent", 50, 20);
        b1.signForm(f1);

    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << '\n';
    }
   }
    return 0;
}