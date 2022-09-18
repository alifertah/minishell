NAME	= minishell
CC		= cc 
RM		= rm -f
CFLAGS	=  -lreadline

HEADER	= minishell.h

SRC		= main.c ft_strdup.c

all: $(NAME)
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	$(RM) $(NAME)

re : fclean all
