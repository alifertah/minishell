NAME	= minishell
CC		= cc 
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -lreadline

HEADER	= minishell.h

SRC		= main.c

all: $(NAME)
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	$(RM) $(NAME)

re : fclean all
