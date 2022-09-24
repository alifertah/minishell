/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:47:21 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/24 15:26:31 by alfertah         ###   ########.fr       */
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
    int j;
    int k;
    int i = 1;

    k = 0;
    j = 0;

        if (!cmd[i + 1])
        {
            printf("\n");
            exit(0);
        }
    while (cmd[i])
    {
        if (!find_only(cmd[i + 1]) && cmd[i + 1] && cmd[i + 1][0] == '-')
        {
            printf("%s ", cmd[i + 1]);
            i++;
        }
        else
        {
            printf("%s\n", cmd[i + 1]);
        }
        i++;
    }
}