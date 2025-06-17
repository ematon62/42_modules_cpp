NAME := bureaucrat3
CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "Compiling binary...\n"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@printf "Done.\n"

clean:
	@printf "Cleaning up...\n"
	@rm -f $(OBJS) *_shrubbery
	@printf "Done.\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJS)