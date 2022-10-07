/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:47:21 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/06 21:32:23 by alfertah         ###   ########.fr       */
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
    int test;

    i = 1;
    test = 0;
    if(!cmd[i])
    {
        printf("\n");
        return ;
    }
    while(cmd[i])
    {
        if(cmd[i][0] == '-' && i == 1)
        {
            while (cmd[i])
            {
                if(find_only(cmd[i]))
                    break;
                test = 1;
                i++;
            }
        }
        if(cmd[i])
            printf("%s ", cmd[i]);
        else 
            break;
     i++;   
    }
    if(test == 0 && !cmd[i])
        printf("\n");
}