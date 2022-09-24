/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:47:21 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/24 17:38:59 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int find_only(char *cmd)
{
    int i;
    i = 1;
    while (cmd[i])
    {
        if (cmd[i] != 'n')
            return 1;
        i++;
    }
    return 0;
}

void ft_echo(char **cmd)
{
    int i;

    i = 2;
    int test = 0;
    if(!cmd[2])
        printf("\n");
    while(cmd[i])
    {
        if(cmd[i][0] == '-' && i == 2)
        {
            while (cmd[i])
            {
                if(find_only(cmd[i]))
                    break;
                test = 1;
                i++;
            }
        }
        if(test == 1)
            printf("%s ", cmd[i]);
        else
            printf("%s\n", cmd[i]);
     i++;   
    }
}