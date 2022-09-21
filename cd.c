/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:51:06 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/21 11:41:49 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cd(char **cmd, int i)
{
        if(cmd[i+1])
        {
            if(!strcmp(cmd[i+1], getCurrentDir()))
            {
                printf("minishell: cd: %s: Not a directory\n", getCurrentDir());
                exit(0);
            }
            chdir(cmd[i+1]);
            printf("%s\n", getcwd(NULL, 0));
            exit(0);
        }
        else
        {
            chdir(getenv("HOME"));
            printf("%s\n", getcwd(NULL, 0));
        }
}