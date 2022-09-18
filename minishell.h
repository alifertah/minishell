/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:23:16 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/18 19:09:53 by alfertah         ###   ########.fr       */
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

t_list *ft_splitter(char *line);
char	*ft_strdup(char *src);
t_list	*ft_lst_new(char *val);

#endif
