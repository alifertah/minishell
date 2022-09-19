/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:47:21 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/19 22:50:12 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_echo(char **cmd, int i)
{
    if(cmd[i+1])
            {
                if(!strcmp(cmd[i+1], "-n"))
                {
                    if(cmd[i + 2])
                        printf("%s", cmd[i+2]);
                    else
                        exit (0);
                }
                else
                    printf("%s\n", cmd[i+1]) ;
            }
            else
                printf("\n");
}