/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:11:11 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/07 05:42:34 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unset(char **av, char** env)
{
    int y;
    y = 0;
            if(av[1])
            {
                while(env[y])
                {
                    if(!strncmp(av[1], env[y], strlen(av[1])))
                    {
                        while(env[y])
                        {
                            if(env[y+1])
                                env[y]=env[y+1]; 
                            else 
                                break;
                            y++;
                        }
                        env[y] =NULL;
                    }
                        y++;
                }
            }
}