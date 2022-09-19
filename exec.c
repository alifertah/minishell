/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:23:12 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/19 22:51:03 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_execute(char **cmd)
{
    int i;
    i = 1;
    while(cmd[i])
    {
        if(!strcmp(cmd[i], "pwd"))
            ft_pwd();
        if(!strcmp(cmd[i], "cd"))
            ft_cd(cmd, i);
        if(!strcmp(cmd[i], "echo"))
        {
            ft_echo(cmd, i);
            exit(0);
        }
    i++;
    }
    
}