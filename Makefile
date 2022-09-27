NAME	= minishell
CC		= cc 
RM		= rm -f
CFLAGS	= 

HEADER	= minishell.h

SRC		= main.c ft_strdup.c pwd.c exec.c cd.c echo.c unset.c dir_only.c env.c export.c count_env.c ft_swap.c  exec_oth.c str_join.c to_lower.c split.c
all: $(NAME)
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	$(RM) $(NAME)

re : fclean all
