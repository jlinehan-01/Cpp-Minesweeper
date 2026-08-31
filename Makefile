# The executable file
EXE = mines

# Compiler
CC = g++

# Formatter
FRMT = clang-format-18

# Compiler flags
CFLAGS = -Wall -Wextra -Wpedantic -Wunused-macros

# Source files
SRC = $(wildcard *.cpp)

# Object files
OBJ = $(SRC:.cpp=.o)

# Libraries to link
#LIB = none atm

# run with make
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

format:
	$(FRMT) -style=file -i *.cpp *.h

# removes object and executable files
clean:
	rm -f *.o $(EXE) *txt
