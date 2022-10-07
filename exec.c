/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:23:12 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/07 05:18:40 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_execute(char **cmd, char **envl)
{
    int pid = 0;
        if(cmd[0])
        {
            to_lower(cmd[0]);
            if(!strcmp(cmd[0], "pwd"))
                ft_pwd();
            else if(!strcmp(cmd[0], "cd"))
                ft_cd(cmd, 0);
            else if(!strcmp(cmd[0], "echo"))
                ft_echo(cmd);
            else if(!strcmp(cmd[0], "unset"))
                ft_unset(cmd, envp);
            else if(!strcmp(cmd[0], "env"))
            {
                
                ft_env(envl);
            }
            else if(!strcmp(cmd[0], "export"))
                ft_export(cmd);
            else
            {
                pid = fork();
                if(pid == 0)
                    exec_ve(cmd);
                wait(0);
            }
        }
}