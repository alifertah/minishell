/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:23:12 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/03 20:26:19 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_execute(char **cmd)
{
        to_lower(cmd[1]);
        if(!strcmp(cmd[1], "pwd"))
            ft_pwd();
        else if(!strcmp(cmd[1], "cd"))
            ft_cd(cmd, 1);
        else if(!strcmp(cmd[1], "echo"))
            ft_echo(cmd);
        else if(!strcmp(cmd[1], "unset"))
            ft_unset(cmd, envp);
        else if(!strcmp(cmd[1], "env"))
            ft_env(envp);
        else if(!strcmp(cmd[1], "export"))
            ft_export(cmd);
        else
            exec_ve(cmd);

    
}