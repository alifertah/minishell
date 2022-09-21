/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:50:31 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/21 11:58:35 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    int y  = 0;
    int x =0;
    char **envi = malloc(sizeof(char *) * 100);
    while(env[x])
    {
        envi[x] = ft_strdup(env[y]);
        y++;
        x++;
    }
    envi[x] = NULL;
    x=0;
    int j  = 1;
    while(av[j])
    {
        ft_execute(av, envi);
        y=0;
        // if(!(strcmp(av[j], "unset")))
        // {
        //     if(av[j+1])
        //     {
        //         while(envi[y])
        //         {
        //             if(!strncmp(av[j+1], envi[y], strlen(av[j+1])))
        //             {
        //                 while(envi[y])
        //                 {
        //                     if(envi[y+1])
        //                         envi[y]=envi[y+1];
        //                     else 
        //                         break;
        //                     y++;
        //                 }
        //                 envi[y] =NULL;
        //             }
        //             y++;
        //         }
        //         for(int i=0;envi[i];i++)
        //             printf("{%s}\n", envi[i]);
        //     }
        //     else
        //         return 0;
        // }
        if(!(strcmp(av[j], "export")))
        {
            if(av[j + 1])
            {
                envi[y] = av[j + 1];
                y++;
                envi[y] = NULL;
            }
        }
        j++;
    }
}
