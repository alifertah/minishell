/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:23:16 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/19 22:49:59 by alfertah         ###   ########.fr       */
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
void    ft_execute(char **cmd);
void    ft_pwd();
void    ft_cd(char **cmd, int i);
void    ft_echo(char **cmd, int i);

#endif
