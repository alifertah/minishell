/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:47:21 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/21 11:16:38 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(char **cmd, int i)
{

    if(!cmd[i+1])
    {
        printf("\n");
        exit(0);
    }
    if(!strcmp(cmd[2], "-n"))
    {  
        while(cmd[i + 2])
        {
            printf("%s ", cmd[i+2]);
            i++;
        }
        exit(0);   
    }
    else
    {
        while(cmd[i] && cmd[i+1] && cmd[i+1])
        {
            printf("%s ", cmd[i+1]);
            i++;
        }
        printf("\n");
        exit(0);
    }
    
}