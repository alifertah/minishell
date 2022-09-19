/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:47:21 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/20 00:19:20 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(char **cmd, int i)
{
    while (cmd[i + 1])
    {
        if (!strcmp(cmd[i + 1], "-n"))
        {
            if (cmd[i + 2])
            {
                printf("%s ", cmd[i + 2]);
                i++;
            }
            else
                exit(0);
        }
        else
            printf("%s ", cmd[i + 1]);
        // else
        //     printf("\n");
        i++;
    }
}