/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:23:16 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/21 11:55:47 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H


#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include<stdlib.h>
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

char	*ft_strdup(char *src);
void    ft_execute(char **cmd, char** envi);
void    ft_pwd();
void    ft_cd(char **cmd, int i);
void    ft_echo(char **cmd, int i);
void    ft_env(char **env);
void    ft_unset(char *var, char** env, int i);
void	*getCurrentDir(void);

#endif
