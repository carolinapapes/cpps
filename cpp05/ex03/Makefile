
# Auto-generated Makefile for folder: ./cpp05/ex03/

BIN_DIR = bin/
INC_DIR = inc/

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g

NAME = ex03

OBJ = bin/Intern.o bin/main.o bin/AForm.o bin/Bureaucrat.o bin/PresidentialPardonForm.o bin/RobotomyRequestForm.o bin/ShrubberyCreationForm.o
DEP = bin/Intern.d bin/main.d bin/AForm.d bin/Bureaucrat.d bin/PresidentialPardonForm.d bin/RobotomyRequestForm.d bin/ShrubberyCreationForm.d

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BIN_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
