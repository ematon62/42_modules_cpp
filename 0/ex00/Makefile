NAME := megaphone
CXX := c++

CXXFLAGS := -Wall -Wextra -Werror 

SRCS := megaphone.cpp

all: $(NAME)

$(NAME):
	@printf "Compiling binary...\n"
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $@
	@printf "Done.\n"

clean:
	@printf "Cleaning up...\n"
	@rm -f $(NAME)
	@printf "Done.\n"

fclean: clean

re: fclean all

.PHONY: all clean fclean re 