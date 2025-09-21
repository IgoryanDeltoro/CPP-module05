TARGET := form28b
CXX := c++
RM := rm -rf
STD := -std=c++98
CFLAGS := -Wall -Wextra -Werror $(STD)
SRC :=	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp
		
OBJ := $(SRC:%.cpp=%.o)
DEPS := $(OBJ:%.o=%.d)
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(TARGET)
%.o: %.cpp
	$(CXX) $(CFLAGS) -MMD -MP -c $< -o $@
clean:
	$(RM) $(OBJ) $(DEPS)
fclean: clean
	$(RM) $(TARGET)
re: fclean all
.PHONY: all clean fclean re
-include $(DEPS)