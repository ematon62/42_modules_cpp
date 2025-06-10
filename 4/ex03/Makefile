NAME := Interface
CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		main.cpp \
		MateriaSource.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "Compiling binary...\n"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@printf "Done.\n"

clean:
	@printf "Cleaning up...\n"
	@rm -f $(OBJS)
	@printf "Done.\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJS)