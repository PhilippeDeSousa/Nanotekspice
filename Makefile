NAME		=		nanotekspice

SRC			=		main.cpp	\
					src/nanotekspice.cpp

OBJS		= 		$(SRC:.cpp=.o)

CC		= 		g++

CPPFLAGS	+= 		-std=c++11 -Wall -Wextra -Iinclude/

RM		= 		rm -f

all: 				$(NAME)

$(NAME): 			$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
				$(RM) $(OBJS)

fclean: 			clean
				$(RM) $(NAME)

re: 				fclean all
				rm -rf $(OBJS)

.PHONY: 			all clean fclean re
