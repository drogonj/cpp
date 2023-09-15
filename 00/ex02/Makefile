NAME  = bank

SRCS  = Account.cpp tests.cpp

OBJS  = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

.cpp.o:
				c++ $(FLAGS) -c $< -o $(<:.cpp=.o)

all:			$(NAME)

$(NAME):	$(OBJS)
				c++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
				rm -f $(OBJS)

fclean: 		clean
				rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
