NAME		=	array

SRCS		=	main.cpp

CC			=	c++

RM			=	rm

CFLAGS		=	-Wall -Werror -Wextra 

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:		
			$(RM) -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re