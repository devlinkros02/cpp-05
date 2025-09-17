# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++11
SRC = ./main.cpp ./Bureaucrat.cpp ./AForm.cpp ./ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)
TARGET = bureaucrat

# Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include ${DEP}

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) ${DEP}

fclean: clean
	rm -f $(TARGET)

re: fclean all

mc: all clean

.PHONY: all clean fclean re