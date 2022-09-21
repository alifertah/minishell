/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:11:11 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/21 12:13:33 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unset(char **av, char** env, int i)
{
    int y;
    int j;

    y = 0;
    j = 1;
    if(!(strcmp(av[j], "unset")))
        {
            if(av[j+1])
            {
                while(env[y])
                {
                    if(!strncmp(av[j+1], env[y], strlen(av[j+1])))
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
                for(int i=0;env[i];i++)
                    printf("{%s}\n", env[i]);
            }
            else
                exit(0);
        }
}