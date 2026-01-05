
# Auto-generated Makefile for folder: ./cpp05/ex01/

BIN_DIR = bin/
INC_DIR = inc/

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g

NAME = ex01

OBJ = bin/Form.o bin/Bureaucrat.o bin/main.o
DEP = bin/Form.d bin/Bureaucrat.d bin/main.d

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
