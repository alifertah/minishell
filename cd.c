/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:51:06 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/25 16:50:13 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cd(char **cmd, int i)
{
        if(cmd[i+1])
        {
            if(!strcmp(cmd[i+1],  "~"))
                chdir(getenv("HOME"));
            if(!strcmp(cmd[i+1], getCurrentDir()))
            {
                printf("minishell: cd: %s: Not a directory\n", getCurrentDir());
                exit(0);
            }
            if(chdir(cmd[i+1]) == -1)
            {
                printf("minishell: cd: %s: No such file or directory\n", cmd[i+1]);
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