/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:50:31 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/19 22:41:36 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    int y  = 0;
    int x =0;
    char **envi = malloc(sizeof(env));
    
    
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
        ft_execute(av);
        if(!(strcmp(av[j], "echo")))
        {
            if(av[j+1])
            {
                if(!strcmp(av[j+1], "-n"))
                {
                    if(av[j + 2])
                        printf("%s", av[j+2]);
                    else
                        return 0;
                }
                else
                    printf("%s\n", av[j+1]) ;
            }
            else
                printf("\n");
        }
        y=0;
        if(!(strcmp(av[j], "unset")))
        {
            if(av[j+1])
            {
                while(envi[y])
                {
                    if(!strncmp(av[j+1], envi[y], strlen(av[j+1])))
                    {
                        while(envi[y])
                        {
                            if(envi[y+1])
                                envi[y]=envi[y+1];
                            else 
                                break;
                            y++;
                        }
                        envi[y] =NULL;
                    }
                    y++;
                }
                for(int i=0;envi[i];i++)
                    printf("{%s}\n", envi[i]);
            }
            else
                return 0;
        }
        if(!(strcmp(av[j], "env")))
        {
            for(int i =0;envi[i]; i++)
                printf("%s\n", envi[i]);
        }
        if(!(strcmp(av[j], "env")))
        {
            int x;
            x = -1;
            while(envi[++x])
                printf("%s\n", envi[x]);
        }
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
