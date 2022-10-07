/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:23:16 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/07 04:44:31 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H


#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct node 
{
	char *val;
	char *type;
	struct node *next;
}t_list;
char  **envp;
char	*ft_strdup(char *src);
void    ft_execute(char **cmd, char **envl);
void    ft_pwd();
void    ft_cd(char **cmd, int i);
void    ft_echo(char **cmd);
void    ft_env(char **env);
void    ft_unset(char **av, char** env);
void	*getCurrentDir(void);
void    ft_export(char **cmd);
void    ft_swap(char *s1, char * s2);
int 	count_env(char **env);
char	*ft_strjoin(char const *s1, char const *s2);
void    exec_ve(char **cmd);
void    to_lower(char *str);
char			**ft_split(const char *str, char c);

#endif
