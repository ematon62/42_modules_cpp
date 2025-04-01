NAME := phonebook
CXX := c++

INC_FLAGS := -Iincludes
CXXFLAGS := -Wall -Wextra -Werror $(INC_FLAGS) -std=c++98

SRCS := srcs/main.cpp \
		srcs/PhoneBook.cpp \
		srcs/Contact.cpp

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