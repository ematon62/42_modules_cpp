NAME := Violence
CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

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