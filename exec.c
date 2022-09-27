/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:23:12 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/27 02:54:13 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_execute(char **cmd)
{
    int i;
    i = 1;
    while(cmd[i])
    {
        to_lower(cmd[i]);
        if(!strcmp(cmd[i], "pwd") || !strcmp(cmd[i], "PWD"))
            ft_pwd();
        else if(!strcmp(cmd[i], "cd"))
            ft_cd(cmd, i);
        else if(!strcmp(cmd[i], "echo"))
            ft_echo(cmd);
        else if(!strcmp(cmd[i], "unset"))
            ft_unset(cmd, envp);
        else if(!strcmp(cmd[i], "env"))
            ft_env(envp);
        else if(!strcmp(cmd[i], "export"))
            ft_export(cmd);
        else
            exec_ve(cmd[i]);
        i++;
    }
}