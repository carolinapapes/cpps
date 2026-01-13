
# Auto-generated Makefile for folder: cpp08/ex01/

BIN_DIR = bin/
INC_DIR = inc/

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g

NAME = ex01

OBJ = bin/main.o bin/Span.o
DEP = bin/main.d bin/Span.d

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
