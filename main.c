/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:50:31 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/19 20:45:00 by alfertah         ###   ########.fr       */
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
        if(!(strcmp(av[j], "pwd")))
            printf("%s\n", getcwd(NULL, 0));
        if(!(strcmp(av[j], "cd")))
        {
            if(av[j+1])
            {
                chdir(av[j+1]);
                printf("%s", getcwd(NULL, 0));
            }
            else
            {
                chdir(getenv("HOME"));
                printf("%s", getcwd(NULL, 0));
            }
        }
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
            
        }
        j++;
    }
}
