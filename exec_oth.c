/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_oth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:56:34 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/27 19:27:41 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    exec_ve(char *cmd)
{
    char *new;
    char **paths = malloc(sizeof(char *) * 100);
    paths=ft_split("/Users/alfertah/.nvm/versions/node/v18.7.0/bin:/Users/alfertah/goinfre/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Users/alfertah/.nvm/versions/node/v18.7.0/bin:/Users/alfertah/goinfre/.brew/bin");
    int i = 0;
    while(paths[i])
    {
        new = paths[i];
        new = ft_strjoin(new, "/");
        new = ft_strjoin(new, cmd);
        if(!access(new, F_OK))
        {
            char *arr[] = {new, NULL};
            execve(new, arr, envp);
        }
            
        i++;
    }
}