#!/usr/bin/env python3
import os
import sys

USAGE = "Usage: python3 makegen.py <target_folder>"

if len(sys.argv) != 2:
    print(USAGE)
    sys.exit(1)

TARGET = sys.argv[1]

if not os.path.isdir(TARGET):
    print("Error: target folder does not exist.")
    sys.exit(1)

# Normalize path + ensure trailing slash
if not TARGET.endswith("/"):
    TARGET += "/"

PROJECT_NAME = os.path.basename(os.path.abspath(TARGET))

CXX = "c++"
CXXFLAGS = "-Wall -Wextra -Werror -std=c++98 -MMD -g"

BIN_DIR = "bin/"
INC_DIR = "inc/"

# -------------------------------------------
# Collect only .cpp files in the target folder
# -------------------------------------------
cpp_files = [f for f in os.listdir(TARGET) if f.endswith(".cpp")]

obj_files = [f"{BIN_DIR}{f.replace('.cpp', '.o')}" for f in cpp_files]
dep_files = [f"{BIN_DIR}{f.replace('.cpp', '.d')}" for f in cpp_files]

# -------------------------------------------
# Build Makefile content
# -------------------------------------------
makefile_content = f"""
# Auto-generated Makefile for folder: {TARGET}

BIN_DIR = {BIN_DIR}
INC_DIR = {INC_DIR}

CXX = {CXX}
CXXFLAGS = {CXXFLAGS}

NAME = {PROJECT_NAME}

OBJ = {' '.join(obj_files)}
DEP = {' '.join(dep_files)}

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
\tmkdir -p $(BIN_DIR)

$(NAME): $(OBJ)
\t$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BIN_DIR)%.o: %.cpp
\t$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
\trm -rf $(BIN_DIR)

fclean: clean
\trm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
"""

# -------------------------------------------
# Write to Makefile in target folder
# -------------------------------------------
with open(TARGET + "Makefile", "w") as f:
    f.write(makefile_content)

print(f"Makefile generated at: {TARGET}Makefile")
