NAME  = Form

SRCS  = srcs/main.cpp srcs/Bureaucrat.cpp srcs/AForm.cpp srcs/ShrubberyCreationForm.cpp srcs/RobotomyRequestForm.cpp srcs/PresidentialPardonForm.cpp

OBJS  = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
				@c++ $(FLAGS) -c $< -o $(<:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@c++ $(FLAGS) $(OBJS) -o $(NAME)
				@printf "\033[32m Done ✓ \033[0m\n"

clean:
				@rm -f $(OBJS)
				@printf "\033[32m Cleaned ✓ \033[0m\n"

fclean: 		clean
				@rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
