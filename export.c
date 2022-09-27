/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:21:37 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/26 17:38:28 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_export(char **cmd)
{
    int j;
    int x;
    int i;
    
    x = 0;
    i = 2;
    char *tmp;
    tmp = NULL;
    j = count_env(envp);
    
    if(!cmd[i])
    {
        while(envp[x])
        {
            int l = x + 1;
            while(envp[l])
            {
                if(strcmp(envp[x], envp[l]) > 0)
                {
                    tmp = envp[x];
                    envp[x] = envp[l];
                    envp[l] = tmp;
                }
                if(strcmp(envp[x], envp[l]) < 0 && envp[l+1])
                    l++;
                if(strcmp(envp[x], envp[l]) == 0)
                    break;
                l++;
            }
            x++;
        }
    }
    while(cmd[i])
    {
        envp[j] = ft_strdup(cmd[i]);
        j++;
        envp[j] = NULL; 
        i++;
    }
    for(int i = 0; envp[i]; i++)
        printf("%s\n", envp[i]);
}