
# Auto-generated capapes Makefile for folder: ./cpp09/ex00/

BIN_DIR = bin/
INC_DIR = inc/

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g

NAME = btc

OBJ = bin/main.o bin/BitcoinExchange.o
DEP = bin/main.d bin/BitcoinExchange.d

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
